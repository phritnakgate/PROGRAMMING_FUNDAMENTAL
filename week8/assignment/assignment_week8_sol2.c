#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main(){
	char str[100];
	char temp;
	int l;
	printf("Input string: ");
	scanf("%s",&str);
	l = strlen(str);
	for(int i=0;i < l;i++){
		if(str[i] >= 97 && str[i] <= 122){
			temp = str[i];
			temp = toupper(temp);
			str[i] = temp;
			temp = 0;
		}
		else if(str[i] >= 65 && str[i] <= 90){
			temp = str[i];
			temp = tolower(temp);
			str[i] = temp;
			temp = 0;
		}
	}
	printf("%s",str);
}