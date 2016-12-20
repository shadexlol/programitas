#include <stdio.h>
#define TAM 128
int procesar_fichero (char nombre_fichero[]);
int main()
{
	int suma=0;
	char nombre_fichero[TAM];
	
	printf("Introduzca el nombre del fichero: \n");
	scanf("%s", nombre_fichero);
	
	suma=procesar_fichero(nombre_fichero);
	printf("La suma es: %d\n",suma);

	return 0;
}

int procesar_fichero (char nombre_fichero[])
{
	int i,a;
	FILE *f;
	int suma=0;	
	
	f=fopen(nombre_fichero,"rt");
	if (f==NULL)
	{
		printf("ERROR! No puedo abrir el fichero.\n");
	}
	else
	{
		fscanf(f, "%d", &a);
		while(!feof(f)) {
			suma += a;
			printf("DATO: %d\n",a);
			fscanf (f, "%d",&a);	
		}
	}
	fclose(f);		
	
	return suma;
}
