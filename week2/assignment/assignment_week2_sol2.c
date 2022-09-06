#include<stdio.h>

void main(){
	int i = 0;
	float total,h;
	printf("Height = ");
	scanf("%f",&h);
		if(h <= 1){
		printf("Please input more than 1!");
	}else{
		total = h;
		while(h>1){
			i++;
			total+=h*0.8;
			h*=0.4;
	}
	printf("Distance = %.2f \n",total);
	printf("Bounce count = %d",i);
	}	
}
