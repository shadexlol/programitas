//Programa 1. 
/*La defirencia entre una libreria propia y una predefinida seria que la propia se definiria
 #include "milibreria."*/
 
 
 
#include <stdio.h> //Contiene las funciones basicas del programa.
#include <math.h>
#define PI 3.1416

int main ()  //funcion principal
	{
	
		float r, res;
		printf ("Deme el \"r\": ");//Con \"r\" podemos escribir las comillas
		scanf ("%f",&r);
		res=4*PI*pow(r,2);
		printf ("El resultado del area es: %.4f\n",res);
		res=PI*pow(r,3)*4/3;
		printf ("El resultado del volumen es: %.4f\n",res);
		
		return 0;
	
	}
		
