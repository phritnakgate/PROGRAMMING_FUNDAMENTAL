#include<stdio.h>

void main(){
	int inp[10];
	for(int i=0;i<10;i++){
		printf(" ");
		scanf("%d",&inp[i]);
	}
	printf("Data in array: ");
	for(int k=0;k<10;k++){
		printf("%d ",inp[k]);
	}
	printf("\n");
	printf("Result: ");
	for(int j=1;j<9;j++){
		if((inp[j-1] % 2 == 1) && (inp[j+1] % 2 == 1)){
			printf("%d ",inp[j]);
		}
	}
}