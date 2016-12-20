#include <stdio.h>

void printvector    (float v[], int n);            /* Para el ejercicio 1 */
float pescalar      (float x[], float y[], int n); /* Para el ejercicio 2 */
int perpendiculares (float x[], float y[], int n); /* Para el ejercicio 7 */

int main()
{
	float a[3] = {4,-5,1};
	float b[3] = {-2,-2,-2};
	float c[5] = {1,0,-2,8,2};
	float d[5] = {3,6,3,1,-3};
	
	/* Aquí vienen las llamadas a funciones según
	dicte cada ejercicio */
	
	printf("Los vectores [");
	printvector(a,3);
	printf("] y [");
	printvector(b,3);
	if (perpendiculares(a,b,3))
		printf("] son perpendiculares.\n");
	else
		printf("] no son perpendiculares.\n");
	
	printf("Los vectores [");
	printvector(c,5);
	printf("] y [");
	printvector(d,5);
	if (perpendiculares(c,d,5))
		printf("] son perpendiculares.\n");
	else
		printf("] no son perpendiculares.\n");
	
	return 0;	
}

/* A partir de aquí vienen las implementaciones de
   las funciones, según dicte cada ejercicio */
void printvector (float v[], int n) {
	int i;
	for (i=0;i<n;i++)
	{
		printf("%f ", v[i]);
	}
}
float pescalar (float x[], float y[], int n) {
	int i;
	float res=0;
	for(i=0;i<n;i++){
		res+=x[i]*y[i];
	}
	return res;
}
int perpendiculares (float x[], float y[], int n) {
	int perpendicular=0;
	if(pescalar(x, y, n)==0.0) {
		perpendicular=1;
	}
	return perpendicular;
}
