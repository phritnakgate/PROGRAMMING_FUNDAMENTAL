#include<stdio.h>

void main(){
	int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
	float sum,average;
	printf("Input 1st Height: ");
	scanf("%d",&s1);
	printf("Input 2nd Height: ");
	scanf("%d",&s2);
	printf("Input 3rd Height: ");
	scanf("%d",&s3);
	printf("Input 4th Height: ");
	scanf("%d",&s4);
	printf("Input 5th Height: ");
	scanf("%d",&s5);
	printf("Input 6th Height: ");
	scanf("%d",&s6);
	printf("Input 7th Height: ");
	scanf("%d",&s7);
	printf("Input 8th Height: ");
	scanf("%d",&s8);
	printf("Input 9th Height: ");
	scanf("%d",&s9);
	printf("Input 10th Height: ");
	scanf("%d",&s10);
	sum = s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 + s9 + s10;
	average = sum / 10;
	printf("Average is %.2f",average);
}