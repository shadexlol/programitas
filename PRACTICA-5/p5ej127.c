#include <stdio.h>

float printvector    (float v[], float n);            /* Para el ejercicio 1 */
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
	
	// EJERCICIO 1 //
	
	printvector(a,3);
	printvector(b,3);
	printvector(c,5);
	printvector(d,5);
	
	// EJERCICIO 2 //
	
	pescalar(a,b,3);
	pescalar(c,d,5);
	
	//
	
	
	
	
	
	
	
	
	return 0;	
}

/* A partir de aquí vienen las implementaciones de
   las funciones, según dicte cada ejercicio */


float printvector (float v[], float n){
	int i;
			printf("[");
				if (n<=3){
					for (i=0; i<2; i++){
						printf("%0.f , ", v[i]);
					}
					
					for (i=2; i<3; i++){
						printf("%0.f", v[i]);
					}
				}
				
			else if (n>3) {
				for (i=0; i<4; i++){
					printf("%0.f , ", v[i]);
				}
				for (i=4; i<5; i++){
					printf("%0.f", v[i]);
				}
			}
					
			printf ("] \n");
}




float pescalar      (float x[], float y[], int n) {
	
	int i;
	float v1,v2,vres1,vres2,vm1,vm2;
		 v1=0;
		 v2=0;
		 vres1=0;
		 vres2=0;
		if (n<=3){
			
			for (i=0; i<3; i++){
				v1=x[i];
				v2=y[i];
				
				vm1=v1*v2;
				vres1=vm1+vres1;			
			}
			printf ("LA SUMA DE LOS VECTORES A Y B ES  :  %0.f \n",vres1);
		}
		else {
			for (i=0; i<5; i++){
				v1=x[i];
				v2=y[i];
				
				vm2=v1*v2;
				vres2=vm2+vres2;
			}
			
		printf ("LA SUMA DE LOS VECTORES C Y D ES  :  %0.f \n",vres2);
	
	
		}
			
}
