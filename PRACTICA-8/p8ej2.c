#include <stdio.h>

#define NUMPERSONAS 20

struct persona
{
	unsigned int dni;
	char letra;
	char nombre[100];
};

int compruebapersona (struct persona p);

int main()
{
	struct persona listapersonas[NUMPERSONAS] =
	{
		{ 27640988, 'W', "Javier Asenjo Gomez" },
		{ 88127409, 'C', "Ignacio Bernet Moreno" },
		{ 28119181, 'W', "Maria de los Angeles Salva Lopez" },
		{ 48855160, 'O', "Susana Oliva Bernal" },
		{ 76221373, 'V', "Sonia Paredes Jarama" },
		{ 77889002, 'P', "Carmen Gerona Altillo" },
		{ 28134243, 'E', "Andres Tolosa Minas" },
		{ 27349085, 'S', "Antonio Sanchez Contreras" },
		{ 77230253, 'R', "Marta Villanueva Odet" },
		{ 28544698, 'L', "Natalia Jimenez Siguero" },
		{ 29684364, 'R', "Isabel Capato Iglesias" },
		{ 78236843, 'C', "Jorge Daniel Zaballa" },
		{ 27972365, 'H', "Luis Rodríguez García" },
		{ 28161495, 'E', "Rocio de Prado Rodriguez" },
		{ 28323403, 'C', "Jose Rosario Lopez" },
		{ 28573203, 'G', "Maria Rodriguez Carmona" },
        { 88238918, 'T', "Juan Boubeta Puig" },
        { 77094623, 'A', "Esteban García Fernandez" },
        { 28032164, 'O', "David Lopez Galeote" },
        { 28497003, 'A', "Belen Viruez Benitez" }
	};

/* Define aqui el resto de variables que necesites en tu programa
   ------------------------------------------------------------- */
	int i,j,a;
	char check[100]={'T','R','W','A','G','N','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};


/* ------------------------------------------------------------- */


/* Escribe a partir de aqui el codigo de este ejercicio:
   Buscar y listar por pantalla: DNI, letra y nombre de todas
   aquellas personas que tengan un error de comprobacion en
   el DNI.
   La letra que se lista es la que aparece almacenada en la
   estructura.
   Usar la función compruebapersona() en este ejercicio.
   ------------------------------------------------------------- */
	for (i=0;i<20;i++){
		 
		 compruebapersona(listapersonas[i]);
		 
		 if (compruebapersona(listapersonas[i])==1){
		 	printf("El DNI es correcto! = %i - %c \t%s \n",listapersonas[i].dni,listapersonas[i].letra,listapersonas[i].nombre);
		 }
		 else{}
			printf ("El DNI es incorrecto! = %i - %c \t%s \n",listapersonas[i].dni,listapersonas[i].letra,listapersonas[i].nombre);
	}




/* ------------------------------------------------------------- */

}

int compruebapersona (struct persona p)
{
	// Escribe aqui el código que comprueba
	// si el DNI de la persona "p" es correcto
	// o no, y devuelve 1 ó 0 según sea el caso.

	int i,j,resto;
	char check[23]={'T','R','W','A','G','N','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};

		resto = p.dni%23;
		
		if (check[resto]==p.letra){
			return 1;
		}
		
		else {
			return 2;
		}
		


}
