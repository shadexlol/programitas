#include <stdio.h>

int main()
{
	int contador=0;
	int acum=0;
	int num;
	int quiero_terminar=0;

	while (!quiero_terminar)
	{
		printf ("Dame un numero positivo (-1 para terminar): ");
		fflush (stdin);
		scanf ("%d", &num);
		if (num==-1)
		{
			quiero_terminar=1;
		}
		else
		{
			contador=contador+1;
			acum=acum+num;
		}
	}

	if (contador>0)
	{
		printf ("La media es: %.2f\n", acum*1.0/contador);
	}
	else
	{
		printf ("Necesito al menos un numero.\n");
	}
	return 0;
}

