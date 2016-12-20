#include <stdio.h>
#include <math.h>


/* Un punto en el espacio */
struct p3d
{
  double x,y,z;
};


/* Prototipo de la función calcula la longitud entre dos puntos/vértices 
   en elespacio:  */
double long_lado (struct p3d punto1, struct p3d punto2);


int main()
{
	double distancia;
	struct p3d p1 = {0, 0, 0};
	struct p3d p2 = {1, 1, 1};
	
	/* Los puntos 'p1' y 'p2' también se podría haber  pedir por teclado. */
	distancia = long_lado (p1, p2);
	
	/* Se muestra por pantalla la 'distancia' entre los 2 puntos/vértices: */
	printf ("La longitud entre los puntos (%lf,%lf,%lf) y (%lf,%lf,%lf) es: %lf \n", p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, distancia);
	
	

	return 0;
}


/* Cuerpo de la funcion 'long_lado'. 
   Se utiliza la fórmula de la distancia euclídea. */
double long_lado (struct p3d punto1, struct p3d punto2)
{
	double res;
	res = sqrt(pow((punto1.x - punto2.x),2)+pow((punto1.y - punto2.y),2)+pow((punto1.z - punto2.z),2));
	return res;	
}

