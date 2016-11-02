#include <stdio.h>

int main ()
{
	
	int a,b,c,n;
	printf("dame un numero que hago una cuenta de 1 hasta tu numero");
	scanf("%d",&n);
	c = 0;
	for (a=1; a<=n ; a++){
		c=c+a;
		}
	printf ("%d",c);
		
	
return 0;
}
