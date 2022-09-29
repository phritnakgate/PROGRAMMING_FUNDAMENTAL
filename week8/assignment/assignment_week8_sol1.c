#include<stdio.h>
#include<string.h>

void main(){
	char str[100];
	int l;
	printf("Input string: ");
	scanf("%s",&str);
	l = strlen(str);
	for(int i=0;i < l;i++){
		if(str[i] >= 65 && str[i] <= 90){
			str[i]+=32;
		}
		else if(str[i] >= 97 && str[i] <= 122){
			str[i]-=32;
		}
	}
	printf("%s",str);
}