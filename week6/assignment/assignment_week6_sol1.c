#include<stdio.h>
#include<string.h>

void main(){
	char c[100];
	printf(" ");
	scanf("%s",&c);
	printf("Last character is %c",c[strlen(c)-1]);
}