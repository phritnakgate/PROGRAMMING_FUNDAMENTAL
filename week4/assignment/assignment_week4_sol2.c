#include<stdio.h>
int Factorial(int f){
	int res=1;
	for(int i=f; i >= 1; i--){
		res*=i;
	}
	return res;
}

void main(){
	int fact;
	printf("Input factorial: ");
	scanf("%d",&fact);
	printf("%d! = %d",fact,Factorial(fact));
}