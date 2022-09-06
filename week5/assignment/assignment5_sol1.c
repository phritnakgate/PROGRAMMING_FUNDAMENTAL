#include<stdio.h>

void main(){
	float height[10];
	float sum = 0.00,avg;
	for(int i=0;i<10;i++){
		printf("Input student %d height: ",i);
		scanf("%f",&height[i]);
		do{
			if(height[i] <= 0){
				printf("Please input positive value only!\n");
				printf("Input student %d height: ",i);
				scanf("%f",&height[i]);
			}else{
				break;
			}
		}while(height[i] < 0);
			sum += height[i];	
		}
	avg = sum / 10;
	printf("Average height is %.2f",avg);
}
