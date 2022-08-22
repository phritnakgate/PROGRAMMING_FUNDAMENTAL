#include<stdio.h>

int checkDivision(int n){
	int temp = 0;
	for(int i=1;i < n;i++){
		if(n % i == 0){
			temp += i;
		}
	}
	return temp;
}

void main(){
	for(int i=1;i<10000;i++){
		if(checkDivision(i) == i){
			printf("P(%d) = %d\n",i,i);
		}
	}
}