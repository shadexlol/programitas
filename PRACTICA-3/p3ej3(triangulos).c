#include <stdio.h>
#include <conio.h>

int main (){
	
	int a,b,c;
	
	printf("DAME LAS LONGUITUDES DE LOS 3 SEGMENTOS SEPARADOS POR ESPACIOS: \n\n\n");
	printf("a\t");
	scanf("%d",&a);
	printf("b\t");
	scanf("%d",&b);
	printf("c\t");
	scanf("%d",&c);
	
	if ( (a+b)>=c && (b+c)>=a && (a+c)>=b ){
		printf("ESTO ES UN TRIANGULO \n");
	}
	else {
		printf ("lo que pusiste no es un triangulo te lo juro \n");
	}
	
	
	
return 0;
}
