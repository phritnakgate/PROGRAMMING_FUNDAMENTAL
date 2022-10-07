#include<stdio.h>
#include<string.h>

void main(){
	int i;
	struct player{
		char name[50];
		int level;
		int score;
	};
	struct player p[5],*ptr;
	ptr = &p;
	char pname[50];
	for(i=0;i < 5;i++){
		printf("Input player name: ");
		scanf("%s",&pname);
		strcpy(p[i].name,pname);
		printf("Input level: ");
		scanf("%d",&p[i].level);
		printf("Input score: ");
		scanf("%d",&p[i].score);
	}
	FILE* fp;
	for(i=0;i < 5;i++){
		if(i == 0){
			fp = fopen("gametestfile.txt","w");
			fprintf(fp,"Name: %s\t",p[i].name);
			fprintf(fp,"Level: %d\t",p[i].level);
			fprintf(fp,"Score: %d\n",p[i].score);
			fclose(fp);
		}else{
			fp = fopen("gametestfile.txt","a");
			fprintf(fp,"Name: %s\t",p[i].name);
			fprintf(fp,"Level: %d\t",p[i].level);
			fprintf(fp,"Score: %d\n",p[i].score);
			fclose(fp);
		}
		
	}
}