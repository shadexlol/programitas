/* Aplicación sencilla para el manejo de figuras 3D en C.
   (C)2008-2009 Miguel Angel Rodriguez Jodar.
   Depto. Arquitectura y Tecnologia de Computadores.
   Universidad de Sevilla.
   Liberado bajo licencia GPL. */

#include <stdio.h>
#include <math.h>
#include "graficos.h"

/* Un punto en el espacio */
struct p3d
{
  double x,y,z;
};

/* Un tríangulo con sus tres vértices. Cada vértice es un punto en el espacio. */
struct triang
{
  struct p3d v1,v2,v3;
};

/* Un objeto hecho con hasta 10000 triángulos */
struct objeto
{
  struct triang caras[10000];
  int numcaras;
};

double long_lado (struct p3d punto1, struct p3d punto2);
int CargarMalla3D (struct objeto *o, char *fichero);
void AnimarMalla3D (struct objeto *o);

int main()
{
	double a,b,c,p,s,s_objeto;
	struct objeto cuerpo;
	
	CargarMalla3D (&cuerpo, "cubo.txt"); /* rellenar la estructura desde los
                                          datos de un fichero. Cambiar el 
										  nombre entre comillas para cargar
										  otros cuerpos 3D */

/* ------------------------------------------------------------------------
   Insertar a partir de aquí el código para el cálculo de la superfície del
   cuerpo 3D.
   Además, calcular también la superfície según la fórmula adecuada para
   cada cuerpo sólido, y comparar resultados.
   ------------------------------------------------------------------------ */

   	printf ("Aqui debe hacerse el calculo de la superficie del objeto que esta siendo\nanimado en la ventana grafica.\n");
   	
	a=long_lado(cuerpo.caras[0].v1,cuerpo.caras[0].v2);
	b=long_lado(cuerpo.caras[0].v1,cuerpo.caras[0].v3);
	c=long_lado(cuerpo.caras[0].v2,cuerpo.caras[0].v3);
	p=(a+b+c)/2.0;
	s=sqrt(p*(p-a)*(p-b)*(p-c)); //Calcula la superficie de un triangulo
	s_objeto=s*cuerpo.numcaras;
	
	printf("Longitud de la arista: %f\n", a);
	printf("Superficie: %f\n",s_objeto);
	
/* ------------------------------------------------------------------------ */
    
	CrearVentanaGraficos();  /* crear la ventana gráfica */
	AnimarMalla3D (&cuerpo);  /* animación 3D del objeto. Termina al pulsar la tecla ESCAPE */
	DestruirVentanaGraficos();  /* destruir la ventana gráfica */

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

