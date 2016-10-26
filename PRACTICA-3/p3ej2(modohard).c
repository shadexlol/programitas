#include <stdio.h>
#include <conio.h>

int main (){
	
	int a,b,c;
	
	printf("Dame en numeros el dia y el mes y te digo en que estacion estamos \n");
	printf("DIA \n");
	scanf("%d",&a);
	printf("MES \n");
	scanf("%d",&b);

	if (b==3){
		if (a>=21){
			printf ("Estamos en PRIMAVERA \n");
		}
		else {
			printf ("ESTAMOS EN INVIERNO \n");
		}
	}
	
	if (b==4){
		printf ("Estamos en PRIMAVERA \n");
	}
	
	if (b==5){
		printf ("Estamos en PRIMAVERA \n");
	}
	
	if (b==6){
		if (a<=20){
			printf ("Estamos en PRIMAVERA\n");
		}
		
		else {
		printf ("Estamos en Verano \n");
		}
	}
		
	if (b==7){
		printf("Estamos en Verano \n");
	}
	
	if (b==8){
		printf("Estamos en Verano \n");
	}
	
	if (b==9){
		if (a<=20){
			printf("Estamos en Verano\n");
		}
		else {
			printf ("Estamos en OTOÑO \n");
		}
	}
	
	if (b==10){
		printf ("Estams en OTOÑO \n");
	}
	
	if (b==11){
		printf ("Estamos en OTOÑO \n");
	}
	
	if (b==12){
		if (a<=20){
			printf ("Estamos en OTOÑO \n");
		}
		else {
			printf ("Estamos en Invierno \n");
		}
	}
	
	if (b==1){
		printf("Estamos en INVIERNO \n");
	}
	
	if (b==2) {
		printf ("Estamos en INVERNO \n");
	}
	
	
return 0;
	}
