#include <stdio.h>
#include <conio.h>

int main (){
	
	int a,b,c;
	
	printf("Dame en numeros el dia y el mes y te digo en que estacion estamos\n");
	printf("DIA \n");
	scanf("%d",&a);
	printf("MES \n");
	scanf("%d",&b);


 // SIEMPRE CUANDO TENEMOS UN IF, LOS CONSECUTIVOS IF LLEVARAN ELSE IF
 // YA QUE INDICAN QUE LA CONDICION SI NO ES ESA, SERA OTRA.
if (a>=21 && b==3 || b==4 || b==5 || b==6 && a<=20){
	printf("Estamos en PRIMAVERA\n");
}

else if (a>20 && b==6 || b==7 ||b ==8 || b==9 && a<20) {
	printf ("Estamos en VERANO \n");
}
else if (a>=20 && b==9 || b==10 || b==11 || b==12 && a<20) {
	printf ("ESTAMOS EN OTOÑO \n");
}
else {
	printf ("INVIERNO \n");
}
return 0;
}
