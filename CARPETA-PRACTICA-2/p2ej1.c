#include <math.h>
#define PI 3.141592654  // PI es una constante que podemos usar

int main()
{
	float a;
	float res;
	
	printf("un valor para el seno de A, comprendido entre 0 y 2pi \n");
	scanf("%f",&a);
	
	printf ("el valor del seno es: %f \n", sin(a));
	printf ("entonces el valor del arsen es; %f \n", asin(sin(a)));
	
	return 0;
	
}
