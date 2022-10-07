#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <random>
//Global Variable
int totalCollision = 0;
bool play = true;
COORD ship;
int posx, posy;
int randomColor = 7;
DWORD numEvents = 0;
DWORD numEventsRead = 0;

//หน้าจอ console
#define screen_x 80
#define screen_y 25
HANDLE wHnd;
COORD bufferSize = { screen_x,screen_y };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
int setConsole(int x, int y) {
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

//ดาว
#define scount 80
COORD star[scount];

//สุ่มพิกัดเริ่มต้นของดาว
void init_star() {
	for (int i = 0; i < scount; i++) {
		star[i] = { SHORT(rand() % screen_x), SHORT(rand() % screen_y) };
	}
}

//Double Buffer
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD characterPos = { 0,0 };
//เตรียมข้อมูลใน buffer
void fill_star_to_buffer() {
	for (int i=0; i < scount; i++) {
		consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
		consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
	}
	
}
//โยนจาก buffer ไป console
void fill_buffer_to_console() {
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos, &windowSize);
}

//เปลี่ยนค่าใน consoleBuffer ทั้งหมดให้แสดงผลเป็นช่องว่างและมีสีเป็นสีขาวไม่มีพื้นหลัง
void clear_buffer() {
	for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 0;
		}
	}
}

//ดาวร่วง
void star_fall() {
	for (int i = 0; i < scount; i++) {
		if (star[i].Y >= screen_y - 1) {
			star[i] = { SHORT(rand() % screen_x),1 };
		}
		else {
			star[i] = { star[i].X,SHORT(star[i].Y + 1) };
		}
	}
}

//Input event
HANDLE rHnd;
DWORD fdwMode;

int setMode(){
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}

//ยาน

void draw_ship() {
	consoleBuffer[ship.X + screen_x * ship.Y].Char.AsciiChar = '<';
	consoleBuffer[ship.X+1 + screen_x * ship.Y].Char.AsciiChar = '-';
	consoleBuffer[ship.X+2 + screen_x * ship.Y].Char.AsciiChar = '0';
	consoleBuffer[ship.X+3 + screen_x * ship.Y].Char.AsciiChar = '-';
	consoleBuffer[ship.X+4 + screen_x * ship.Y].Char.AsciiChar = '>';
	consoleBuffer[ship.X + screen_x * ship.Y].Attributes = randomColor;
	consoleBuffer[ship.X+1 + screen_x * ship.Y].Attributes = randomColor;
	consoleBuffer[ship.X+2 + screen_x * ship.Y].Attributes = randomColor;
	consoleBuffer[ship.X+3 + screen_x * ship.Y].Attributes = randomColor;
	consoleBuffer[ship.X+4 + screen_x * ship.Y].Attributes = randomColor;
}

void checkCollision()
{
	for (int i = 0; i < scount; i++)
	{
		if ((star[i].X == ship.X || star[i].X == ship.X + 1 || star[i].X == ship.X + 2) && star[i].Y == ship.Y)
		{
			star[i] = { SHORT(rand() % screen_x), 1 };
			totalCollision++;
		}
		if (totalCollision == 10)
		{
			play = false;
		}
	}
}



//MAIN
int main() {
	srand(time(NULL));
	setConsole(screen_x, screen_y);
	init_star();
	setMode();
	
	while (play) {
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) {
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i) {
				if (eventBuffer[i].EventType == KEY_EVENT &&
					eventBuffer[i].Event.KeyEvent.bKeyDown == true) {
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
						play = false;
					}
					else if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 99) {
						randomColor = rand() % 7;
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) {
					posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
						randomColor = rand() % 7;
					}
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {
						ship.X = posx;
						ship.Y = posy;
					}
				}
			}
			delete[] eventBuffer;
		}
		star_fall();
		clear_buffer();	
		checkCollision();
		fill_star_to_buffer();
		draw_ship();
		fill_buffer_to_console();
		Sleep(100);
	}
		
	return 0;
}