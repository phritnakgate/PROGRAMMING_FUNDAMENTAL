#include<stdio.h>

void main(){
	int x= 10, y= 20 , z=30 ,*p1 ,*p2;
	p1 =&x;
	p2 =&y;
	printf("%d %d %d %d %d \n",x,y,z ,*p1 ,*p2);
	x=80;
	printf("%d %d %d %d %d \n" ,x,y,z ,*p1 ,*p2);
	p1 =&z;
	p2 = p1;
	printf("%d %d %d %d %d \n" ,x,y,z ,*p1 ,*p2);
	*p1=100;
	printf("%d %d %d %d %d \n ",x,y,z ,*p1 ,*p2);
	p1 = &x;
	x = y + *p1;
	printf("Last: %d %d %d %d %d \n",x,y,z ,*p1 ,*p2);
}
