#include <stdio.h>

int numerorango (int);

int main()
{
	int n,b;
	printf("introdusca un numero etnre 0 y 9\n");
 	scanf("%d",&b);
	n = numerorango(b);
	printf ("El numero introducido es %d\n", n);
	return 0;
}

int numerorango (int h)
{
	int i,res;
 
		for (i=0 ; i<=9 && res!=h ; i=i+1){
			if (h<i || h>9){
				printf("dame otro cabron\n \t");
				fflush(stdin);
				scanf("%d",&h);
			}
			else {
			
				res = h;
			}
			
		}
	return res;	
}
