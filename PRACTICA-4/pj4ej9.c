#include <stdio.h>
#include <conio.h>
 
int main() {
    long decimal,n;
    int resto;
    long binario = 0, i =1;
    
    printf("Mete un numero decimal\n");
    scanf("%d", &decimal);
    
		while(decimal != 0) {
        resto = decimal%2;
        decimal = decimal/2;
        binario = binario + (resto*i);
        i = i*10;
    }
	
	printf("El numero binario es: %d \t", binario);
     
    return 0;
}
