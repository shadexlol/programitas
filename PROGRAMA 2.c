//Programa 2. USO DE FUNCIONES 

#include <stdio.h> //Contiene las funciones basicas del programa.
#include <math.h>
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
	 float area (float a)
	 	{
	 		float res1;
	 		res1=4*PI*pow(a,2);
	 		return res1;  //devolvemos nuestro resultado
	 	
		 }
	 float volumen (float b)
	 {
	 	float res1;
	 	res1=pow(b,3)*PI*4/3;
	 	return res1;
	 }
	 	
	 	
	 	
	 	
	 	
	 	
	 	
