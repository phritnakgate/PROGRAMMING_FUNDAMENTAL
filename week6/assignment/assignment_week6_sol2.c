#include<stdio.h>
#include<string.h>

void main(){
	char c[100],r;
	int l;
	printf(" ");
	scanf("%s",&c);
	l = strlen(c);
	for(int i=0;i <= l+1;i++){
		r = c[i];
		if(c[i] == NULL){
			printf("Last character is %c",c[i-1]);
			break;
		}
	}
}