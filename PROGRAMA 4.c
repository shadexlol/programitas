//Como declarar un menu.

#include <stdio.h> //Contiene las funciones basicas del programa.
#include <math.h>
#include "milibreria.h"
#define PI 3.1416

float area (float a);
float volumen (float b);

int main ()  //funcion principal
	{
		int opcion;
		float r, res;
		int salir = 0 ;
		printf ("Deme el \"r\": ");//Con \"r\" podemos escribir las comillas
		scanf ("%f",&r);
		
		while (salir ==0)
		{
			
			printf("Seleccione una de las opciones: \n");
			printf("\t1) Calculo del area\n");
			printf("\t2) Calculo del Volumen\n");
			printf("\t3) Cambiar el valor de \"r\"\n");
			printf("\t0)Salir\n\t\t");
			scanf ("%d",&opcion);
		
		switch (opcion)
		{
			case 1:
			res= area (r);
			printf ("El resultado del area es: %.4f\n",res);
			break;
			
			case 2:
			res= volumen (r);
			printf ("El resultado del volumen es: %.4f\n",res);
			break;
			  
			case 3:
			printf ("Escriba el nuevo valor para\"r\": ");//Con \"r\" podemos escribir las comillas
			scanf ("%f",&r);
			break;
			
			case 0:
			printf("ADIOS\n");
			salir=1;
			break;
				
			default: //Esta opcion sirve para descartar cualquier numero que no pertenezca a los seleccionados
			printf("Opcion incorrecta\n");
			break;
		}
		}
		return 0;
	}
