#include<stdio.h>

void main(){
	int i;
	float total,h;
	printf("Height = ");
	scanf("%f",&h);
	if(h <= 1){
		total = h;
		i = 1;
		printf("Distance = %.2f \n",total);
		printf("Bounce count = %d",i);
	}else{
		total = h;
		for(i=0;h > 1;i++){
			total += h*0.4*2;
			h*=0.4;
	}
	printf("Distance = %.2f \n",total);
	printf("Bounce count = %d",i);
	}
	
}
