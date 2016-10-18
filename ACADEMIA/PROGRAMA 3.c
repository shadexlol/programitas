//Como crear una libreria nueva.

#include <stdio.h> //Contiene las funciones basicas del programa.
#include <math.h>
#include "milibreria.h"
#define PI 3.1416

float area (float a);
float volumen (float b);

int main ()  //funcion principal
	{
	
		float r, res;
		printf ("Deme el \"r\": ");//Con \"r\" podemos escribir las comillas
		scanf ("%f",&r);
		res= area (r);
		printf ("El resultado del area es: %.4f\n",res);
		res= volumen (r);
		printf ("El resultado del volumen es: %.4f\n",res);
		
		return 0;
	}
