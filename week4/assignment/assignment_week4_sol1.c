#include<stdio.h>
int Factorial(int f){
	int res=1;
	for(int i=1; i <= f; i++){
		res*=i;
	}
	return res;
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
