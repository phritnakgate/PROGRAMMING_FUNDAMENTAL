#include<stdio.h>
int main(){
	int num,factor=2;
	printf("Enter number: ");
	scanf("%d",&num);
	while(num != 1){
        while(num % factor == 0){
            printf("%d",factor);
            num /= factor;
            if(num!=1){
            	printf("x");
			}
        }
		factor++;
    }
	return 0;
}
