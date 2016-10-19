#include <math.h>

int main()
{
	float x,b;
	float res;
	
	// Prueba el programa con los valores 4,8,16,256,65536 y 1048576
	x = 
	b = 2;

	// Completa esta línea para que calcule el logaritmo en base B de X
	res = 
	
	return 0;
}






// PARTE DEL EJERCICIO 7 // 


#include <math.h>
#include <stdio.h>

float logb (float, float);

int main()
{
	float x,b,res;
	
	printf("dame  la base y el argumento \n");
	scanf("%f",&x);
	scanf("%f",&b);
	res = logb(x,b);
	printf("sol: %f\n", res);
	

	
	return 0;
}

float logb (float y, float z){
	return log(y)/log(z);
}
