#define PI 3.141592654
#include <math.h>

float cuadrado (float);  // <- este es el prototipo de la función cuadrado()

int main()
{
	float a;
	float sena,cosa;
	float senac,cosac;
	float res;
	
	// Dale un valor a la variable "a" para probar el programa
	a = 8;
	sena = sin(a);
	cosa = cos(a);
	senac = cuadrado(sena);
	cosac = cuadrado(cosa);
	res = senac + cosac;
	
	return 0;
}

float cuadrado (float a)  // <- aquí comienza el cuerpo de la función cuadrado()
{
	float resultado;
	
	resultado = a*a;
	return resultado;
}
