#include <stdio.h>


void printvector    (int v[], int n);            /* Para el ejercicio 1 */

int main()
{
	int a[3] = {4,-5,1};
	int b[3] = {-2,-2,-2};
	int	c[5] = {1,0,-2,8,2};
	int	d[5] = {3,6,3,1,-3};
	int	f[6]= {2,1,1,1,1,1,1};
	
	/* Aquí vienen las llamadas a funciones según
	dicte cada ejercicio */
	printvector(a, 3);
	printvector(b, 3);
	printvector(c, 5);
	printvector(d, 5);
	printvector(f, 6);
				
	return 0;	
}

/* A partir de aquí vienen las implementaciones de
   las funciones, según dicte cada ejercicio */
void printvector (int v[], int n) {
	int i;
	for (i=0;i<n;i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}
