/* Aplicación sencilla para el manejo de figuras 3D en C.
   (C)2008-2009 Miguel Angel Rodriguez Jodar.
   Depto. Arquitectura y Tecnologia de Computadores.
   Universidad de Sevilla.
   Liberado bajo licencia GPL. */

#include <windows.h>

#define NEGRO (RGB(0,0,0))
#define AZUL (RGB(0,0,255))
#define ROJO (RGB(255,0,0))
#define MAGENTA (RGB(255,0,255))
#define VERDE (RGB(0,255,0))
#define CYAN (RGB(0,255,255))
#define AMARILLO (RGB(255,255,0))
#define BLANCO (RGB(255,255,255))
#define NARANJA (RGB(128,128,0))
#define MARRON (RGB(128,0,0))
#define GRIS (RGB(128,128,128))

int CrearVentanaGraficos (void);
int DestruirVentanaGraficos (void);
void Punto (int x, int y, COLORREF c);
void Linea (int x1, int y1, int x2, int y2, COLORREF c);
void Circulo (int xc, int yc, int radio, COLORREF c);
void Triangulo (int x1, int y1, int x2, int y2, int x3, int y3, COLORREF c, COLORREF r);
void Refrescar (void);
void Borrar (void);
