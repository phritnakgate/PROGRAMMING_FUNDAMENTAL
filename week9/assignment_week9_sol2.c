#include<stdio.h>

int rew=0;

int reward(int freebott){
	int gift,remainbottle,totalremain;
	gift = freebott / 3;
	remainbottle = freebott % 3;
	totalremain = gift + remainbottle;
	rew += gift;
	if(totalremain / 3 != 0){
		return reward(totalremain);
	}else{
		return 0;
	}
}

void main(){
	int buy;
	printf("Input bottle: ");
	scanf("%d",&buy);
	if(buy >= 1 && buy <= 300){
		if(buy == 1 || buy == 2){
			printf("Total = %d",buy);
		}else{
			reward(buy);
			printf("Total = %d",buy + rew);
		}
	}else{
		printf("Input in range 1-300 only!");
	}
}