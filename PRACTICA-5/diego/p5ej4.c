#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int i,cont;
	char mensaje[1000];
	cont=0;
	
	printf("Escriba un mensaje: \n");
	fflush(stdin);
	gets(mensaje);
	for(i=0;i<strlen(mensaje);i++)
	{
		if( 'a'<=mensaje[i] && mensaje[i]<='z' ) {
		
			mensaje[i]=mensaje[i]-32;
		}
		
		printf("%c",mensaje[i]);
	}
	printf("\n");
	
	return 0;
}
