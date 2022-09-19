#include<stdio.h>

void swap(int *a, int *b){
	int llb;
	llb = *b;
	*b = *a;
	*a = llb;
}

void main(){
	int la,lb;
	printf("Input two numbers: ");
	scanf_s("%d %d",&la,&lb);
	swap(&la,&lb);
	printf("%d %d",la,lb);

}