#include<stdio.h>
#include<conio.h>
#include<Windows.h>

void draw_ship(int x,int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("<-0->");
}

void erase_ship(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("     ");
}

void main() {
	
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x > 0) { 
				erase_ship(x, y);
				draw_ship(--x, y); }
			if (ch == 'd' && x <= 80) { 
				erase_ship(x, y);
				draw_ship(++x, y); }
			if (ch == 'w' && y > 0) { 
				erase_ship(x, y);
				draw_ship(x, --y); }
			if (ch == 's' && y <= 25) {
				erase_ship(x, y);
				draw_ship(x, ++y); }
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	
}