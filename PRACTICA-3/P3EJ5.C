#include <stdio.h>

/* Prototipo de la funcion "calificar" */
float calificar (float, float, float, float, float, float);

int main (void)
{
	float p1,p2,t1,t2,t3,t4,N;
	
	printf ("las notas de practica \n");
	printf("p1    "); scanf("%f",&p1);
	printf("p2    "); scanf("%f",&p2);
	
	printf ("las notas de teoria \n");
	printf("t1   ");scanf("%f",&t1);
	printf("t2   ");scanf("%f",&t2);
	printf("t3   ");scanf("%f",&t3);
	printf("t4   ");scanf("%f",&t4);
	
	N = calificar(t1,t2,t3,t4,p1,p2);
	
	if (N<5){
		printf ("suspenso");
	}
	
	if (N>=5 && N<7){
		printf ("APROBADO");
	}
	
	if (N>=7 && N<9){
		printf ("NOTABLE");
	}
	
	if (N>=9) {
		printf ("sobre");
		if (N>9.5){
			printf ("OPTA A MATRICULA");
		}
	}
	   
	
	return 0;	
}

/* Cuerpo de la funcion "calificar" */
float calificar (float t1, float t2, float t3, float t4, float p1, float p2)
{

	if (p1+p2>=1.5 && t1+t2+t3+t4>=1.5){		
	
	return t1+t2+t3+t4+p1+p2;
	}
	
	else return 0;
	
	
}
