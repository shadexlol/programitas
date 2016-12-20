#include <stdio.h>

#define LONMENSAJE 1024

int main()
{
	char mensaje[LONMENSAJE];
	char sms[LONMENSAJE];
	int i,j;
	j=0;	
	printf ("Dame el mensaje: ");
	fflush (stdin);
	gets (mensaje);

	/* Sigue a partir de aqui... */
	for(i=0;i<strlen(mensaje);i++) {	
		if(mensaje[i] !='a' && mensaje[i] !='e' && mensaje[i] !='u' && mensaje[i] !='q') {
			sms[j]=mensaje[i];
			j++;
		} else { 
			if(mensaje[i]=='q') {
				sms[j]='k';
				j++;
			}
		}
	}
	sms[j]=0;

	/* Imprime SMS y su longitud... */
	printf ("El mensaje convertido es: %s\n", sms);
	printf ("Su longitud: %d caracteres\n", strlen(sms));
		
	return 0;
}
