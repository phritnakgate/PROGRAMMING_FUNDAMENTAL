#include<stdio.h>

void main(){
	int inp[10];
	int isDividedbytwo[10];
	for(int i=0;i<10;i++){
		printf(" ");
		scanf("%d",&inp[i]);
		isDividedbytwo[i] = inp[i] % 2;
	}
	printf("Data in array: ");
	for(int k=0;k<10;k++){
		printf("%d ",inp[k]);
	}
	printf("\n");
	printf("Result: ");
	for(int j=1;j<9;j++){
		if((isDividedbytwo[j-1] == 1) && (isDividedbytwo[j] == 0) &&(isDividedbytwo[j+1] == 1)){
			printf("%d ",inp[j]);
		}
	}
}