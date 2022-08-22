#include<stdio.h>

void main(){
	int num,t,s,result;
	printf(" ");
	scanf("%d",&num);
	if(num < 100 || num > 999){
		printf("Put value between 100-999 only naja!");
	}
	else{
		do{
			s = num % 10;
			num -= s;
			num /= 10;
			t = num % 10;
			num -= t;
			num /= 10;
			result = num * s * t;
			printf("%dx%dx%d = %d\n",num,t,s,result);
			num = result;
		}while(result != 0);
	}
}