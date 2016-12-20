#include <stdio.h>
#include <string.h>
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
		if( 'e'==mensaje[i] || 'E'==mensaje[i] ) 
			cont++;
	}
	printf ("\nEn este mensaje aparence %d veces la letra e.\n",cont);
	
	return 0;
}
