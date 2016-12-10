#include <stdio.h>
#define TMEMORIA 15

int main (){

	int mem[TMEMORIA]={};
	int i,j;
	
	FILE * f1;
	
	f1 = fopen ("resultado.txt","w");
	
	if (f1 == NULL){
		printf ("NO SE A PODIDO ACCEDDER AL ARCHIVO");
	}
	else {
	
		for (j=0;j<=TMEMORIA;j++){
			mem[j]=j;
			fprintf(f1,"%4.4i \n",mem[j]);
		}
		fclose(f1);
	}






}
