#include <stdio.h>


	int main (){

short int a,b,i,j,c;

	FILE * f;
	f=fopen("numero.txt","rt");
		if(f==NULL){
			printf("no se pudo abrir el archivo");
		}
		
		else {
		
		while (1){
			c = fgetc(f);
			if (feof(f)){
				break;
			}
			a = c%3;
			if (a==0){
				printf("el numero %c es divisible entre 3\n",c);
			}
			else {
				printf("el %c no es divisble amigo\n",c);
			}
		}
		fclose(f);
		
		return 0;		
		
		
		}





}
