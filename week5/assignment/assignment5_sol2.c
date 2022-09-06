#include<stdio.h>
#include<string.h>

void main(){
	char inp[100],temp;
	char aca[] = "aca";
	int right_index,len;
	printf("Welcome to Karaca Encoder\n");
	printf("Input string(a-z): ");
	scanf("%s",&inp);
	//1. Reverse String
	right_index = strlen(inp) - 1;
	for(int i = 0; i < right_index; i++)  
    {  
        temp = inp[i];  
        inp[i] = inp[right_index];  
        inp[right_index] = temp;  
        right_index--;  
    }  
	//2. Change vowel to number
	len = strlen(inp);
	for(int i=0; i < len; i++){
		if(inp[i] == 'a'){
			inp[i] = '0';
		}
		else if(inp[i] == 'e'){
			inp[i] = '1';
		}
		else if(inp[i] == 'i'){
			inp[i] = '2';
		}
		else if(inp[i] == 'o'){
			inp[i] = '3';
		}
		else if(inp[i] == 'u'){
			inp[i] = '4';
		}
	}
	//3. Fill aca
	strcat(inp,aca);
	printf("Encoded: %s",inp);
}