git add doc



#define h 0.83333
#define g 1.12
#include <stdio.h>
#include <stdlib.h>

void main ()
{
	float num1,num2;
	float E;
	int a;
	
	printf("1.- Euros a Dolares \n");
	printf("2.- Dolares a Euros \n");
	printf("Seleccione la opcion 1 u opcion 2 escribiendo el numero \n");
	scanf("%d", &a);
	
	system("cls");
	
	if (a == 1){
	printf("Ponga sus euros\n");
	scanf("%f", &num1);
	
	printf("El valor es: %0.2f", (E=num1*g));
	
	}
	
	if (a == 2){
	printf("Ponga sus dolares\n");
	scanf("%f", &num2);
	
	printf ("El valor es: %0.2f \n\n\n\n", (E=num2*h));
	printf("\n \n");
	}
	
	return 0;
	
}
