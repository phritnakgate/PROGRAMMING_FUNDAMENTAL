#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main(){
	char text[100];
	char text_upper[100];
	scanf("%s",&text);
	for(int i=0;i < strlen(text); i++){
		if(text[i] >= 65 && text[i] <= 90){
			printf("%c",text[i]);	
		}
	}
}