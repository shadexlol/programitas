#include <stdio.h>
#include <math.h>
#include <conio.h>

int main (){

float a,e,res;
	e=0;

	printf("dame un valor ");
	scanf("%f",&a);
	
	while(a>=2){
		if (a>=2){
			a = a/2;
			e = e+1;
		}
	}
	
	printf ("valor del numero %f \t valor de la mantisa %f \n",a,e);
	
	return 0;
			
		
		
