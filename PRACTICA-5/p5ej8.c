#include <stdio.h>

int main()
{
	int esprimo[101]; /* para contener numeros del 1 al 100 */
	int i,n,m;
	
	for (i=1;i<=100;i++)
	{
		esprimo[i] = 1;  /* asumo que todos son primos, al principio */
	}
	
	/* Sigue aqui el ejercicio... */
	n=2;
	while(n<100) {
		m=2;
		while(n*m<100) {
			esprimo[n*m]=0;
			m=m+1;
		}
		n=n+1;
		while(esprimo[n]==0 && n<100) {
			n=n+1;
		}
	}
	
	/* Imprimir lista de numeros primos */
	for (i=1;i<=100;i++)
	{
		if (esprimo[i])  /* si es primo... */
		{
			printf ("%d ", i);  /* ...lo imprimimos */
		}
	}
	return 0;
}
