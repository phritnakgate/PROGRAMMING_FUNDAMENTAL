#include<stdio.h>

int isPrime(int num){
	int check = 1;
	//Check 0,1,2
		if(num == 0 || num == 1){
			check = 0;
		}
		else if (num == 2){
			check = 1;
		}
		//Check others
		else{
			for(int i = 2; i < num; i++){
				if(num%i == 0){
					check = 0;
					break;	
				}
			}
		}
	return check;
}
void main(){
	int number;
	printf("Input Positive Integer: ");
	scanf("%d",&number);
	if(isPrime(number) == 1){
		printf("%d is Prime Number.",number);
	}
	else{
		printf("%d is not Prime Number.",number);
	}
}