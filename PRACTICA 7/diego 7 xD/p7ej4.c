#include <stdio.h>
#define TAM 128
int procesar_fichero (char nombre_fichero[]);
int main()
{
	int suma=0;
	char nombre_fichero[TAM];
	
	printf("Introduzca el nombre del fichero: \n");
	scanf("%s", nombre_fichero);
	
	if( procesar_fichero(nombre_fichero) )
	{
		printf("El numero es multiplo de 3\n");
	}

	return 0;
}

int procesar_fichero (char nombre_fichero[])
{
	int i,a;
	FILE *f;
	int suma=0;	
	int multiplo=0;
	
	f=fopen(nombre_fichero,"rt");
	if (f==NULL)
	{
		printf("ERROR! No puedo abrir el fichero.\n");
	}
	else
	{
		printf("Abrimos el fichero.\n");
		fscanf(f, "%1d", &a);
		while(!feof(f))
		{
			suma+=a;
			fscanf (f, "%1d",&a);
		//	printf("%d\n",suma);	
		}
		if(suma%3==0)
		{
			multiplo=1;
		}
	}
	fclose(f);
	
	
	return multiplo;
}
