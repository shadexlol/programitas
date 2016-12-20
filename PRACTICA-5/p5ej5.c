#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,cont,dado1,dado2;
	int tiradas[13];
	
	for(i=0;i<13;i++) {
		tiradas[i]=0;	
	}

	for(i=0;i<1000;i++)
	{
		dado1 = 1+rand()*6/RAND_MAX;
		dado2 = 1+rand()*6/RAND_MAX;
		tiradas[dado1+dado2]++;
	}
	
	for(i=2;i<13;i++) {
		printf("El %d ha salido: %d veces\n", i, tiradas[i]);	
	}

	return 0;
}
