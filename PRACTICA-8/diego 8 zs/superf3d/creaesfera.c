/* Aplicación sencilla para el manejo de figuras 3D en C.
   (C)2008-2009 Miguel Angel Rodriguez Jodar.
   Depto. Arquitectura y Tecnologia de Computadores.
   Universidad de Sevilla.
   Liberado bajo licencia GPL. */

#include <stdio.h>
#include <math.h>

#define NUMRAD 25
#define RAD 300
#define PI 3.141592654

int main (void)
{
	FILE *fc;
	double esfera[NUMRAD+1][NUMRAD][3];
	int i,j;
	double ang,ang2,rad;
	
	fc=fopen("esfera.txt","wt");
	for (i=0;i<=NUMRAD/2;i++)
	{
		ang=(i*90/(NUMRAD/2.0))*PI/180;
		rad=RAD*sin(ang);
		for (j=0;j<NUMRAD;j++)
		{
			ang2=(j*360.0/NUMRAD)*PI/180;
			
			esfera[i][j][0]=rad*cos(ang2);
			esfera[i][j][1]=RAD*cos(ang);
			esfera[i][j][2]=rad*sin(ang2);

			esfera[NUMRAD-i][j][0]=rad*cos(ang2);
			esfera[NUMRAD-i][j][1]=-RAD*cos(ang);
			esfera[NUMRAD-i][j][2]=rad*sin(ang2);
		}
	}
	
	for (i=0;i<NUMRAD;i++)
		for (j=0;j<NUMRAD;j++)
		{
			fprintf (fc,"%lf %lf %lf\n", esfera[i][j][0], esfera[i][j][1], esfera[i][j][2]);
			fprintf (fc,"%lf %lf %lf\n", esfera[i][(j+1)%NUMRAD][0], esfera[i][(j+1)%NUMRAD][1], esfera[i][(j+1)%NUMRAD][2]);
			fprintf (fc,"%lf %lf %lf\n", esfera[i+1][j][0], esfera[i+1][j][1], esfera[i+1][j][2]);

			fprintf (fc,"%lf %lf %lf\n", esfera[i+1][j][0], esfera[i+1][j][1], esfera[i+1][j][2]);
			fprintf (fc,"%lf %lf %lf\n", esfera[i+1][(j+1)%NUMRAD][0], esfera[i+1][(j+1)%NUMRAD][1], esfera[i+1][(j+1)%NUMRAD][2]);
			fprintf (fc,"%lf %lf %lf\n", esfera[i][(j+1)%NUMRAD][0], esfera[i][(j+1)%NUMRAD][1], esfera[i][(j+1)%NUMRAD][2]);
		}
		
	fclose (fc);
}
		
