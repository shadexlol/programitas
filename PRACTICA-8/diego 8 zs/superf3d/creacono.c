/* Aplicación sencilla para el manejo de figuras 3D en C.
   (C)2008-2009 Miguel Angel Rodriguez Jodar.
   Depto. Arquitectura y Tecnologia de Computadores.
   Universidad de Sevilla.
   Liberado bajo licencia GPL. */

#include <stdio.h>
#include <math.h>

#define NUMRAD 40
#define RAD 200
#define ALTURA 500
#define PI 3.141592654

int main (void)
{
	FILE *fc;
	double circs[NUMRAD][3];
	int i;
	double ang;
	
	fc=fopen("cono.txt","wt");
	for (i=0;i<NUMRAD;i++)
	{
		ang=(i*360.0/NUMRAD)*PI/180;
		circs[i][0]=RAD*cos(ang);
		circs[i][2]=RAD*sin(ang);
		circs[i][1]=-ALTURA/2.0;
	}
	
	for (i=0;i<NUMRAD;i++)
	{
		fprintf (fc,"%lf %lf %lf\n", circs[i][0], circs[i][1], circs[i][2]);
		fprintf (fc,"%lf %lf %lf\n", circs[(i+1)%NUMRAD][0], circs[(i+1)%NUMRAD][1], circs[(i+1)%NUMRAD][2]);
		fprintf (fc, "0 %lf 0\n", -ALTURA/2.0);
	}
	
	for (i=0;i<NUMRAD;i++)
	{
		fprintf (fc,"%lf %lf %lf\n", circs[i][0], circs[i][1], circs[i][2]);
		fprintf (fc,"%lf %lf %lf\n", circs[(i+1)%NUMRAD][0], circs[(i+1)%NUMRAD][1], circs[(i+1)%NUMRAD][2]);
		fprintf (fc,"%lf %lf %lf\n", 0.0, ALTURA/2.0, 0.0);
	}
	
	fclose (fc);
}

		
		
