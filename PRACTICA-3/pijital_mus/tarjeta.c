#include <stdio.h>

/*
Esta es la función que se ha de completar. No se debe escribir nada fuera de
las llaves que delimitan la función. Se pueden añadir más #include's si fueran
necesarios.
Tampoco se necesita escribir el prototipo de esta función. Tan solo rellenar
su código.
Pueden declararse más variables si las necesitais. Se han declarado algunas
variables que sí serán necesarias:

cmd : este es el comando proveniente del decodificador. Es un número de 8 bits.
Es el parámetro de la función.
resp : aquí se guardará la respuesta que se calcule de la tarjeta, y que se
devolverá como valor de la función. También es un número de 8 bits.
anterior : es una variable estática, necesaria para el ejercicio 9 (no se usa
en el ejercicio 8). Úsala para guardar el valor del comando de forma que la
siguiente vez que se llame a la función "tarjeta", esta variable aún "recuerde"
cuál fue el comando que se envió la vez anterior.

Para guardar números de 8 bits (un byte) usamos el tipo "unsigned char"
*/

unsigned char tarjeta (unsigned char cmd)
{
	unsigned char resp;
	static unsigned char anterior=0;
	
	/* Empieza a escribir aquí tu código */






	anterior = cmd; /* guardamos el comando, de forma que cuando se vuelva a
                       llamar a esta función, anterior conserve, efectivamente,
                       el mensaje "anterior" . Lo usaremos en el ejercicio 9 */
	return resp;	
}
