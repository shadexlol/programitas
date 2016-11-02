#include <stdio.h>

int main ()
{
	
	int a,b,c,n;
	printf("dame un numero que hago una cuenta de 1 hasta tu numero");
	scanf("%d",&n);
	
	for (a=1; a<=n ; a++){
		b = ((1+a)*a)/2;
	}
	printf ("%d",b);
		
	
return 0;
}
