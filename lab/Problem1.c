#include<stdio.h>

int sumNumber(int n){
	int result = 0;
	while(n / 10 != 0){
		result += (n % 10);
		n /= 10;
	}
	result += n;
	return result;
}

void main(){
	int num,res;
	printf("Input Number: ");
	scanf("%d",&num);
	res = sumNumber(num);
	printf("Result is %d \n",res);
	while(res > 10){
		res = sumNumber(res);
		printf("Result is %d \n",res);
	}
}