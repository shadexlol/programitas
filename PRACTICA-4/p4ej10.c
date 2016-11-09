#include <stdio.h>
#include <math.h>


int main () {

 int primero=0, segundo=1, siguiente,c;
 // int n;
 // printf ("introduzca el numero de terminos que desea saber de la sucesion"); 
 // scanf ("%d",&n
 		
 	
 	for (c=0; c<20; c++){
 		if (c<=1)
 		siguiente = c;
 		else {
 			siguiente = primero + segundo;
 			primero = segundo;
 			segundo = siguiente;
 		}
 		
	printf ("%d\n",siguiente);
 	}
	return 0;
}
 		
// OTRA FORMA DE HACERLO ESTA FORMA ES LA QUE YO HE PENSADO DESPUES DE HACER ESTE CODIGO DE AQUI ARRIBA, LO MIRE Y LO PENSE Y LUEGO LO ELABORE
// DE LA FORMA INDICADA.



#include <stdio.h>
#include <conio.h>

int main (void) {


	int primero, segundo, sucesion, c;
	
	primero=0;
	segundo=1;
		
		for (c=0; c<10; c++) {
			if (c<=1)
				sucesion = c;
			else {
				sucesion = primero + segundo;
				primero = segundo;
				segundo = sucesion;
			}
		printf ("%d\n",sucesion);
		}
				
