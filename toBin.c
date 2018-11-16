#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void to_binario(char binario[],int num){
	0x1000;
	int mask = 0x8000;
	if(mask &  num){
		strcpy(binario,"1");
		}
		else{
		 strcpy(binario,"0");
		}
		mask = mask >> 1;
	while(mask !=0 ){
		if(mask &  num){
		strcat(binario,"1");
		}
		else{
		 strcat(binario,"0");
		}
		mask = mask >> 1;
	}
}
int main(){
char binario[16];
int num = 11;
	to_binario(binario,num);
	printf("%s\n",binario);
}