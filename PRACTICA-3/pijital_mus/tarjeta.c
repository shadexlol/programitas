#include <stdio.h>

/*
Esta es la funci�n que se ha de completar. No se debe escribir nada fuera de
las llaves que delimitan la funci�n. Se pueden a�adir m�s #include's si fueran
necesarios.
Tampoco se necesita escribir el prototipo de esta funci�n. Tan solo rellenar
su c�digo.
Pueden declararse m�s variables si las necesitais. Se han declarado algunas
variables que s� ser�n necesarias:

cmd : este es el comando proveniente del decodificador. Es un n�mero de 8 bits.
Es el par�metro de la funci�n.
resp : aqu� se guardar� la respuesta que se calcule de la tarjeta, y que se
devolver� como valor de la funci�n. Tambi�n es un n�mero de 8 bits.
anterior : es una variable est�tica, necesaria para el ejercicio 9 (no se usa
en el ejercicio 8). �sala para guardar el valor del comando de forma que la
siguiente vez que se llame a la funci�n "tarjeta", esta variable a�n "recuerde"
cu�l fue el comando que se envi� la vez anterior.

Para guardar n�meros de 8 bits (un byte) usamos el tipo "unsigned char"
*/

unsigned char tarjeta (unsigned char cmd)
{
	unsigned char resp;
	static unsigned char anterior=0;
	
	/* Empieza a escribir aqu� tu c�digo */






	anterior = cmd; /* guardamos el comando, de forma que cuando se vuelva a
                       llamar a esta funci�n, anterior conserve, efectivamente,
                       el mensaje "anterior" . Lo usaremos en el ejercicio 9 */
	return resp;	
}
