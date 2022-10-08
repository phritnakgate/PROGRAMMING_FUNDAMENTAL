#include<stdio.h>

void main(){
	int firstbuy,totalbottle,freebottle = 0,remain,totalremain;
	printf("Input bottle: ");
	scanf("%d",&firstbuy);
	if(firstbuy >= 1 && firstbuy <= 300){
		if(firstbuy == 1 || firstbuy == 2){
			printf("Total = %d",firstbuy);
		}else{
			totalbottle = firstbuy;
			totalremain = firstbuy;
			do{
				freebottle = totalremain / 3;
				remain = totalremain % 3;
				totalremain = remain + (totalremain / 3); 
				totalbottle += freebottle;
			}while(freebottle != 0);
			
			printf("Total = %d",totalbottle);
		}
	}else{
		printf("Input in range 1-300 only!");
	}
}