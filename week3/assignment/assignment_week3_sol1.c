#include<stdio.h>

void main(){
	int num,h,t,s;
	printf(" ");
	scanf("%d",&num);
	if(num < 100 || num > 999){
		printf("Put value between 100-999 only naja!");
	}
	else{
		do{
			t = num / 100;
			h = (num - t*100) / 10;
			s = num - t*100 - h*10;
			printf("%dx%dx%d = %d \n",t,h,s,t*h*s);
			num = t*h*s;	
		}while(t*h*s != 0);
	}
}