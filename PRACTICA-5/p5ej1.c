#include <stdio.h>

void printvector    (float v[], int n);            /* Para el ejercicio 1 */

int main()
{
	float a[3] = {4,-5,1};
	float b[3] = {-2,-2,-2};
	float c[5] = {1,0,-2,8,2};
	float d[5] = {3,6,3,1,-3};
	
	/* Aqu� vienen las llamadas a funciones seg�n
	dicte cada ejercicio */
	printvector(a, 3);
	printvector(b, 3);
	printvector(c, 5);
	printvector(d, 5);
				
	return 0;	
}

/* A partir de aqu� vienen las implementaciones de
   las funciones, seg�n dicte cada ejercicio */
void printvector (float v[], int n) {
	int i;
	for (i=0;i<n;i++)
	{
		printf("%f ", v[i]);
	}
	printf("\n");
}
