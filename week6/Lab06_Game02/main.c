#include<stdio.h>
#include<conio.h>
#include<Windows.h>

//แก้ปัญหา identifier bool is undefined
#ifndef __cplusplus
	typedef unsigned char bool;
	static const bool False = 0;
	static const bool True = 1;
#endif

//สี
void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

//วาดยาน
void draw_ship(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(2, 4);
	printf("<-0->");
}

//ลบยาน
void erase_ship(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(2, 0);
	printf("     ");
}

//ลบ Cursor
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

//วาดกระสุน
void draw_bullet(int x,int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(7, 1);
	printf(" | ");
}
//ลบกระสุน
void erase_bullet(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(7, 0);
	printf("   ");
}

void main() {
	char ch = ' ';
	int direction = 0;
	bool bullet_status[6];
	bool spacebar_state = TRUE;
	int x = 38, y = 20;								//Ship Position
	int bx[6], by[6],max_bullet = 5,bullet = 0;		//Bullet Position + Counter
	setcursor(0);
	draw_ship(x, y);

	do {
		//เช็คปุ่ม
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') {;
				direction = 1; //1 = Left
			}
			if (ch == 'd') { 
				direction = 2; //2 = Right
			}
			if (ch == 's') {
				direction = 0; //0 = Stop
			}
			if (ch == ' ') {
				if (spacebar_state == TRUE) {
					if (bullet < max_bullet) {
						bullet += 1;
						bx[bullet] = x + 1;
						by[bullet] = 19;
						bullet_status[bullet] = TRUE;
						Sleep(100);
					}
					else {
						spacebar_state = FALSE;
						Sleep(250);
					}
				}
				else {
					bullet = 0;
					for (int j = 0; j < 6; j++) {
						bullet_status[j] = FALSE;
					}
					spacebar_state = TRUE;
					Sleep(100);
				}
				
			}
			fflush(stdin);
		}
		//Logic ยานเคลื่อนที่
		if (direction == 1 && x != 0) {
			erase_ship(x, y);
			draw_ship(--x, y);
			
		}
		if (direction == 2 && x != 80) {
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (direction == 0 || x == 0 || x == 80) {
			draw_ship(x, y);
		}
		//Logic กระสุน
		for (int i = 1; i <= bullet; i++) {
			if(bullet_status[i] == TRUE) {
				erase_bullet(bx[i], by[i]);
				if (by[i] > 0) {
					draw_bullet(bx[i], --by[i]);
				}
				else {
					bullet_status[i] = FALSE;
				}
			}
		}
		Sleep(100);
	} while (ch != 'x');
	
}