#include<stdio.h>
int main(){
	int n;
	printf("");
	scanf("%d",&n);
	if(n>=1){
		//New Line
		for(int i=0;i<n;i++){
			//Print * & space on each line
			for(int j=0; j<n; j++){
				if(i == 0 || j == 0 || i == n-1 || j == n-1){
					printf("*");
				}
				else{
					printf(" ");
				}
		}
		printf("\n");
		}
	}
	else{
		printf("ERROR!");
	}
	return 0;
}
