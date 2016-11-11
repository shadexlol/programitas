#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
int main (){

	char v[1000];
	int i, b,c;
	
	gets(v);
	
	b=0;
	c=0;
	
	for (i=0; i<strlen(v); i++){
		
		if (v[i]=='E'){
			b = b+1;
		}
		
		else if (v[i]=='e'){
			c = c+1;
		}
		
		else {}
	}
		printf ("n\n\n\n");
		printf ("hay tantas E grandes; %d \nHay tantas e pequeñas: %d \n\n",b,c);
	
	return 0;
}
	
	
	
