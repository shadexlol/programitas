#include <stdio.h>

#define M 3
#define N 4

int ElementoMayorMatriz (int t[M][N]);

int main()
{
	int tabla[M][N] = { 
						{3, 5, 12, 1},
	                    {6, 11, 4, 8},
						{7, 10, 2, 9}
	                  };
    int mayor;
	int a;
	unsigned char i,j;
	
	printf ("Imprimir los valores de 'tabla' de mayor a menor\n");
	for (a=0;a<M*N;a++)  /* Bucle que da 12 vueltas */
	{
		mayor = ElementoMayorMatriz(tabla);  /* Buscamos el elemento mayor */
		i = (mayor>>8)&0xFF;   /* Obtenemos sus coordenadas */
		j = mayor&0xFF;
		printf ("%d ", tabla[i][j]);  /* Lo imprimimos */
		tabla[i][j] = -1;   /* Y lo marcamos para que no vuelva a aparecer */
	}
	printf ("\n");
	return 0;
}

/* Escribe a partir de aqui la funcion ElementoMayorMatriz */

int ElementoMayorMatriz (int t[M][N])
{
	int i,j;
	int mayor=0;
	char imayor=0;
	char jmayor=0;
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(t[i][j] > t[imayor][jmayor])
			{
				imayor=i;
				jmayor=j;
			}
		}	
	}
	mayor=(imayor<<8) | jmayor;
	
	return mayor;
}

