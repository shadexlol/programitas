#define PI 3.141592654
#include <math.h>

float cuadrado (float);  // <- este es el prototipo de la funci�n cuadrado()

int main()
{
	float a;
	float sena,cosa;
	float senac,cosac;
	float res;
	
	// Dale un valor a la variable "a" para probar el programa
	a =
	sena = sin(a);
	cosa = cos(a);
	senac = cuadrado(sena);
	cosac = cuadrado(cosa);
	res = senac + cosac;
	
	return 0;
}

float cuadrado (float n)  // <- aqu� comienza el cuerpo de la funci�n cuadrado()
{
	float resultado;
	
	resultado = n*n;
	return resultado;
}
