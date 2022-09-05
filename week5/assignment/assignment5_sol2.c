#include<stdio.h>


void main(){
	int height[10];
	float sum = 0,average;
	for(int i; i < 10; i++){
		printf("Input Height: ");
		scanf("%d",&height[i]);
	}
	sum = height[0] + height[1] + height[2] + height[3] + height[4] + height[5] + height[6] + height[7] + height[8] + height[9];
	average = sum / 10;
	printf("Average height is %.2f",average);
}