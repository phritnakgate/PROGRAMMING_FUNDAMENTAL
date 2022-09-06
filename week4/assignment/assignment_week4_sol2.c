#include<stdio.h>

int Factorial(int f){
	if(f == 0 || f == 1){
		return 1;
	}
	else{
		return f * Factorial(f-1);
	}
}

void main(){
	int fact;
	printf("Input factorial: ");
	scanf("%d",&fact);
	if(fact < 0){
		printf("Error! Input zero or positive integer only!");
	}
	else{
		printf("%d! = %d",fact,Factorial(fact));
	}
}
