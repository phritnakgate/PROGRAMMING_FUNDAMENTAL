#include<stdio.h>

int main(){
	int n,y;
	int x=1;
	printf("");
	scanf("%d",&n);
	for(x=1;x<=n;++x){
		y=1;
		for(y = 1;y<=x;++y){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}