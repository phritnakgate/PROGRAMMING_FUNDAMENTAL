#include<stdio.h>

void drawStar(int st){
	while(st--){
		printf("*");
	}
}
void drawSpace(int sp){
	while(sp--){
		printf(" ");
	}
}

void main(){
	int h,spaces;
	printf(" ");
	scanf("%d",&h);
	spaces = 2 * (h - 1);
	for(int i=1;i <= h; i++){
		drawStar(i);
		drawSpace(spaces);
		drawStar(i);
		spaces -= 2;
		printf("\n");
	}
	spaces = 2;
	for(int i=h-1;i > 0; i--){
		drawStar(i);
		drawSpace(spaces);
		drawStar(i);
		spaces += 2;
		printf("\n");
	}
}