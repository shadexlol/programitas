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
 		
