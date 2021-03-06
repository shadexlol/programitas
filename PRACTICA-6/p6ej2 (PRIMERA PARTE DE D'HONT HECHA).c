#include <stdio.h>

#define NUMPARTIDOS 5
#define NUMESCANOS 7

void CargarEscrutinio    (int v[NUMPARTIDOS]);
void RepartoDHondt       (int t[NUMESCANOS+1][NUMPARTIDOS]);
void RepartoRestoMayor   (int t[3][NUMPARTIDOS]);
int  ElementoMayorMatriz (int t[NUMESCANOS][NUMPARTIDOS]);
int  ElementoMayorVector (int v[NUMPARTIDOS]);
void ImprimirReparto     (char titulo[], int v[NUMPARTIDOS]);

int main()
{
	int tabladhondt[NUMESCANOS+1][NUMPARTIDOS];
	int tablaresto[3][NUMPARTIDOS];
	

	CargarEscrutinio (tabladhondt[0]);
	RepartoDHondt (tabladhondt);
	ImprimirReparto ("Reparto por el metodo D'Hondt", tabladhondt[NUMESCANOS]);
	CargarEscrutinio (tablaresto[0]);
	RepartoRestoMayor (tablaresto);
	ImprimirReparto ("Reparto por el metodo del resto mayor", tablaresto[1]);
	return 0;
}

void CargarEscrutinio (int v[NUMPARTIDOS])
{
	v[0] = 340000;
	v[1] = 280000;
	v[2] = 160000;
	v[3] = 60000;
	v[4] = 15000;
}

int ElementoMayorMatriz (int t[NUMESCANOS][NUMPARTIDOS])
{
	int i,j;
	int im,jm;
	
	im=0;
	jm=0;
	
	for (i=0;i<6;i++){
		for(j=0;i<4;j++){
			
			if (t[i][j] > t[im][jm]) {
				
				im=i;
				jm=j;
			}
		}
	}


	return ((im&0xFF)<<8) | (jm&0xFF);
}

int ElementoMayorVector (int v[NUMPARTIDOS])
{









}

void RepartoDHondt (int t[NUMESCANOS+1][NUMPARTIDOS])
{
	int i,j;
	int mayor;
	int im,jm;
	int b,c,a;
	
	b=0;
	c=0;

	for (i=7; i<8; i++){
		for (j=0; j<5; j++){
			t[i][j]=0;
		}
	}
	
	/* Rellenar las filas 1 a NUMESCANOS-1 con los valores resultantes de
	dividir el numero de votos de un partido entre el valor (i+1). */

	for (i=1; i<7; i++){
		for(j=0;j<5;j++){
			t[0][j]=b;
			c = b/2;
			t[i][j]=c;
		}
	}
	/* Repetir esto tantas veces como escaños haya: buscar el elemento de mayor
	valor en la matriz (elemento de coordenadas im,jm). Sumarle 1 al número de 
	escaños del partido al que corresponde ese elemento, y por último, poner 
	ese elemento de la matriz a -1 para que ya no vuelva a ser el mayor */
	for (a=0;a<6*4;a++)
	{
		mayor = ElementoMayorMatriz(t);
		im = (mayor>>8)&0xFF;
		jm = mayor&0xFF;
		t[i][j] = -1;
	}






	}
	/* Fin del algoritmo. Los escaños obtenidos están en la última fila de la
	la matriz, la fila NUMESCANOS */
}

void RepartoRestoMayor (int t[3][NUMPARTIDOS])
{
	int q;
	int totalvotos=0;
	int restoescanos=0;
	int i,k,mayor;
	
	/* Contabilizar el total de votos obtenidos sumando los obtenidos por 
	todos los partidos. El total de votos se guardará en la variable totalvotos */





		
	/* Aplicamos uno de los cocientes (descomentar el que se vaya a usar */
	q = (int)(0.5 + totalvotos*1.0/NUMESCANOS);  /* cociente Hare */
	//q = (int)(1.5 + totalvotos*1.0/(NUMESCANOS+1)); /* cociente Droop */
	//q = (int)(0.5 + totalvotos*1.0/(NUMESCANOS+2)); /* cociente Imperiali */
	
	/* Repetir para cada partido: guardar en la fila 1 el cociente entre el
	numero de votos de un partido y Q. Guardar en la fila 2 el resto de la divi-
	sión entre el número de votos de un partido y Q. */
	
	




	
	
	/* Contabilizar el total de escaños conseguidos hasta ahora por todos los
	partidos. Estos escaños están en la fila 1 de la matriz. El total de
	escaños se guardará en la variable restoescanos */




	/* Calculamos el valor de K */		
	k = NUMESCANOS - restoescanos;
	
	/* Repetir K veces esto: buscamos el elemento mayor de toda la fila 2. Al
	partido que le corresponde ese elemento mayor se le suma un escaño más (los
	escaños obtenidos están en la fila 1). Por último, se guarda un -1 en el
	elemento encontrado como mayor, para que no vuelva a ser encontrado */
	for (    COMPLETAR ESTE FOR   )
	{
		mayor = ElementoMayorVector (t[2]);






	}
	/* Fin del algoritmo. Los escaños obtenidos están en la fila 1 de la matriz */
}
	
void ImprimirReparto (char titulo[], int v[NUMPARTIDOS])
{
	int i;
	
	printf ("\n%s\n", titulo);	

	for (i=0;i<NUMPARTIDOS;i++)
		printf ("Partido %2d: %3d escanos\n", i+1, v[i]);
}
