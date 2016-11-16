#include <stdio.h>

#define M 3
#define N 4

int ElementoMayorMatriz (int t[M][N]);

int main()
{
	int tabla[M][N] = { 
						{3, 5, 12, 1},
	                    {6, 11, 4, 8},
						{7, 10, 2, 9}
	                  };
    int mayor;
	int a;
	unsigned char i,j;
	
	printf ("Imprimir los valores de 'tabla' de mayor a menor\n");
	for (a=0;a<M*N;a++)  /* Bucle que da 12 vueltas */
	{
		mayor = ElementoMayorMatriz(tabla);  /* Buscamos el elemento mayor */
		i = (mayor>>8) & 0xFF;   /* Obtenemos sus coordenadas */
		j = mayor & 0xFF; /* & ----> MULTIPLICACION BOULEANA */
		printf ("%d ", tabla[i][j]);  /* Lo imprimimos */
		tabla[i][j] = -1;   /* Y lo marcamos para que no vuelva a aparecer */
	}
	printf ("\n");
	return 0;
}

/* Escribe a partir de aqui la funcion ElementoMayorMatriz */
int ElementoMayorMatriz (int t[M][N])
{
	int imayor, jmayor, i , j;
	
	imayor = 0; // Vamos a empezar a recorrer la matriz desde [0][0].
	jmayor = 0;
	
	// Recorrido por filas.
	     // Recorrer la fila 0
	     // Recorrer la fila 1
	     // ....
	     // Recorrer la fila M-1
    
	/* Para recorrer todas estas filas usamos un bucle for */
    
	for(i=0; i<M; i++)
    {
    	// Recorrer la fila i
    	     // Acceder al elemento de fila i columna 0.
    	     // Acceder al elemento de fila i columna 1.
    	     //...
    	     // Acceder al elemento de fila i columna N-1.
       
	   /* Lo recorremos con otro bucle for. */
	   
	   for(j=0;j<N;j++)
	   {
	   	// Acceder al elemento de fila i columna j, esto es equivalente a ----->
	   	// -------> Acceder al elemento t[i][j]
	   	// SI matriz[i][j]>matriz[imayor][jmayor] ENTONCES
             // imayor <-- i
             // jmayor <-- j
        //FINSI
        if(t[i][j] > t[imayor][jmayor])
        {
        	imayor = i;
        	jmayor = j;
	   	}
    }
    
}
//Devolver imayor, jmayor
return (imayor<<8)| jmayor;
}
   

