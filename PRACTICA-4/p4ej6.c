#include <stdio.h>

int main() {

int a,b,c;
	
		for(c=1; c<=200; c=c+1){
		if (c%3==0 && c%5==0){
			printf("fizzbuzz\n");
		}
		else if (c%3==0){
			printf("fizz\n");
		}
		else if (c%5==0){
			printf("buzzlmaooo\n");
		}
		else {
			printf("%d\n",c);
		}
	}
return 0;
}
