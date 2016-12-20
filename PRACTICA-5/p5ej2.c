#include <stdio.h>

float pescalar      (float x[], float y[], int n); /* Para el ejercicio 2 */

int main()
{
	float a[3] = {4,-5,1};
	float b[3] = {-2,-2,-2};
	float c[5] = {1,0,-2,8,2};
	float d[5] = {3,6,3,1,-3};
	
	/* Aquí vienen las llamadas a funciones según
	dicte cada ejercicio */	
	printf("Resultado a*b: %f\n", pescalar(a, b, 3));
	printf("Resultado c*d: %f\n", pescalar(c, d, 5));
				
	return 0;	
}

/* A partir de aquí vienen las implementaciones de
   las funciones, según dicte cada ejercicio */
float pescalar (float x[], float y[], int n) {
	int i;
	float res=0;
	for(i=0;i<n;i++){
		res+=x[i]*y[i];
	}
	return res;
}
