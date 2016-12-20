/* Aplicación sencilla para el manejo de figuras 3D en C.
   (C)2008-2009 Miguel Angel Rodriguez Jodar.
   Depto. Arquitectura y Tecnologia de Computadores.
   Universidad de Sevilla.
   Liberado bajo licencia GPL. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <process.h>
#include "graficos.h"

#define ANCHOVENT 800
#define ALTOVENT 600
#define GROSORLINEA 2
#define LEJE 40

/* El punto de vista del observador */
#define PVX 0
#define PVY 0
#define PVZ (-1000)

struct p3d
{
  double x,y,z;
};

struct triang
{
  struct p3d v1,v2,v3;
};

struct objeto
{
  struct triang caras[10000];
  int numcaras;
};

HANDLE threadid;
HINSTANCE hInst;
HWND hWnd;
HDC hdcBuffer=NULL;
HBITMAP hBitmapBuffer=NULL,hBitmapOrig;

volatile int VentanaCreada;

DWORD WINAPI ProcesoVentana (LPVOID parametro);
long WINAPI WndProc (HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
int compara_triang (const void *t1, const void *t2);

int CrearVentanaGraficos (void)
{
	HDC hDCW;
	VentanaCreada=0;
	threadid=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ProcesoVentana,NULL,0,NULL);
	if (!threadid)
		return 0;
	else
	{
		while (!VentanaCreada)
			Sleep(10);
		if (VentanaCreada==1)
		{
			hDCW=GetDC(hWnd);
			hdcBuffer=CreateCompatibleDC(hDCW);
			hBitmapBuffer=CreateCompatibleBitmap(hDCW, ANCHOVENT, ALTOVENT);
			hBitmapOrig=SelectObject(hdcBuffer, hBitmapBuffer);
			ReleaseDC(hWnd,hDCW);
			return 1;
		}
		else
			return 0;
	}
}

int DestruirVentanaGraficos (void)
{
	if (hdcBuffer)
	{
		SelectObject (hdcBuffer, hBitmapOrig);
		DeleteObject (hBitmapBuffer);
		DeleteDC (hdcBuffer);
	}
	SendMessage(hWnd,WM_CLOSE,0,0);
	while (VentanaCreada!=-1)
		Sleep(10);
		
	return 1;
}

void Punto (int x, int y, COLORREF c)
{
	x+=(ANCHOVENT/2);
	y=(ALTOVENT/2)-y;
	SetPixel(hdcBuffer,x,y,c);
}

void Linea (int x1, int y1, int x2, int y2, COLORREF c)
{
	HPEN hpen,hpenant;
	
	x1+=(ANCHOVENT/2);
	y1=(ALTOVENT/2)-y1;
	x2+=(ANCHOVENT/2);
	y2=(ALTOVENT/2)-y2;
	hpen=CreatePen(PS_SOLID,GROSORLINEA,c);
	hpenant=SelectObject(hdcBuffer,hpen);
	MoveToEx(hdcBuffer,x1,y1,NULL);
	LineTo(hdcBuffer,x2,y2);
	SetPixel(hdcBuffer,x2,y2,c);
	SelectObject(hdcBuffer,hpenant);
	DeleteObject(hpen);
}

void Triangulo (int x1, int y1, int x2, int y2,int x3, int y3, COLORREF c, COLORREF r)
{
	HPEN hpen,hpenant;
	HBRUSH hbrush,hbrushant;
	POINT puntos[3];
	
	x1+=(ANCHOVENT/2);
	y1=(ALTOVENT/2)-y1;
	x2+=(ANCHOVENT/2);
	y2=(ALTOVENT/2)-y2;
	x3+=(ANCHOVENT/2);
	y3=(ALTOVENT/2)-y3;

	hpen=CreatePen(PS_SOLID,GROSORLINEA,c);
	hpenant=SelectObject(hdcBuffer,hpen);
	hbrush=CreateSolidBrush(r);
	hbrushant=SelectObject(hdcBuffer,hbrush);
	
	puntos[0].x=x1;
	puntos[0].y=y1;
	puntos[1].x=x2;
	puntos[1].y=y2;
	puntos[2].x=x3;
	puntos[2].y=y3;
	Polygon (hdcBuffer, puntos, 3);

	SelectObject(hdcBuffer,hbrushant);
	DeleteObject(hbrush);
	SelectObject(hdcBuffer,hpenant);
	DeleteObject(hpen);
}

void Circulo (int xc, int yc, int radio, COLORREF c)
{
	HPEN hpen,hpenant;
	int x1,y1,x2,y2;

	xc+=(ANCHOVENT/2);
	yc=(ALTOVENT/2)-yc;
	x1=xc-radio;
	y1=yc-radio;
	x2=xc+radio;
	y2=yc+radio;
	hpen=CreatePen(PS_SOLID,GROSORLINEA,c);
	hpenant=SelectObject(hdcBuffer,hpen);
	SelectObject(hdcBuffer,GetStockObject(NULL_BRUSH));
	Ellipse(hdcBuffer,x1,y1,x2,y2);
	SelectObject(hdcBuffer,hpenant);
	DeleteObject(hpen);
}

void Borrar (void)
{
    HPEN hpen,hpenant;

	BitBlt (hdcBuffer, 0, 0, ANCHOVENT, ALTOVENT, hdcBuffer, 0, 0, SRCERASE);

	SetBkColor(hdcBuffer,NEGRO);
	hpen=CreatePen(PS_SOLID,0,ROJO);
	hpenant=SelectObject(hdcBuffer,hpen);
	MoveToEx(hdcBuffer,4,ALTOVENT-8,NULL);
	LineTo(hdcBuffer,4+LEJE,ALTOVENT-8);
	MoveToEx(hdcBuffer,4,ALTOVENT-8,NULL);
	LineTo(hdcBuffer,4,ALTOVENT-8-LEJE);
	/*MoveToEx(hdcBuffer,4,ALTOVENT-8,NULL);
	LineTo(hdcBuffer,(LEJE-4)*0.8,(ALTOVENT-LEJE*0.8));*/
	SelectObject(hdcBuffer,hpenant);
	DeleteObject(hpen);
}

void Refrescar (void)
{
	HDC hdc;
	int res;
	
	hdc=GetDC(hWnd);
	res=BitBlt (hdc, 0, 0, ANCHOVENT, ALTOVENT, hdcBuffer, 0, 0, SRCCOPY);
	ReleaseDC(hWnd,hdc);
}

DWORD WINAPI ProcesoVentana (LPVOID parametro)
{
    static char szappname[]="practica_fi";
    MSG         msg;
    WNDCLASS    wndclass;

	hInst=GetModuleHandle(NULL);

    wndclass.style=CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wndclass.lpfnWndProc= (WNDPROC) WndProc;
    wndclass.cbClsExtra=0;
    wndclass.cbWndExtra=0;
    wndclass.hInstance=hInst;
    wndclass.hIcon=LoadIcon(NULL, IDC_ICON);
    wndclass.hCursor=LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground=GetStockObject(BLACK_BRUSH);
    wndclass.lpszMenuName=NULL;
    wndclass.lpszClassName=szappname;
    RegisterClass(&wndclass);

    hWnd=CreateWindow(szappname,"Ventana de salida de gráficos",WS_BORDER,
                      CW_USEDEFAULT,CW_USEDEFAULT,ANCHOVENT,ALTOVENT+20,GetDesktopWindow(),NULL,hInst,NULL);

	if (hWnd==NULL)
	{
		VentanaCreada=-1;
		return 0;
	}

    ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

    while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
    }

    VentanaCreada=-1;
    return 0;
}

long WINAPI WndProc (HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
     HDC hdc;
     PAINTSTRUCT ps;

     switch (message)
     {                     
       case WM_CREATE:
            VentanaCreada=1;
            return 0;

       case WM_PAINT:
			hdc=BeginPaint(hwnd, &ps);
			BitBlt (hdc, 0, 0, ANCHOVENT, ALTOVENT, hdcBuffer, 0, 0, SRCCOPY);			
			EndPaint (hwnd, &ps);
			return 0;

       case WM_CLOSE:
            DestroyWindow (hwnd);
			return 0;

       case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
     }
     return DefWindowProc(hwnd,message,wparam,lparam);
}

int CargarMalla3D (struct objeto *o, char *fichero)
{
	FILE *f;
	
	o->numcaras=0;
	
	f=fopen(fichero, "rt");
	if (!f)
		return 0;
		
	fscanf (f, "%lf%lf%lf", &o->caras[o->numcaras].v1.x,
	                     &o->caras[o->numcaras].v1.y,
	                     &o->caras[o->numcaras].v1.z);
	fscanf (f, "%lf%lf%lf", &o->caras[o->numcaras].v2.x,
	                     &o->caras[o->numcaras].v2.y,
	                     &o->caras[o->numcaras].v2.z);
	fscanf (f, "%lf%lf%lf", &o->caras[o->numcaras].v3.x,
	                     &o->caras[o->numcaras].v3.y,
	                     &o->caras[o->numcaras].v3.z);
	                     
   	o->numcaras++;
    while (!feof(f))
    {
    	if (o->numcaras==10000)
    		break;
    		
		fscanf (f, "%lf%lf%lf", &o->caras[o->numcaras].v1.x,
	                     &o->caras[o->numcaras].v1.y,
	                     &o->caras[o->numcaras].v1.z);
		fscanf (f, "%lf%lf%lf", &o->caras[o->numcaras].v2.x,
	                     &o->caras[o->numcaras].v2.y,
	                     &o->caras[o->numcaras].v2.z);
		fscanf (f, "%lf%lf%lf", &o->caras[o->numcaras].v3.x,
	                     &o->caras[o->numcaras].v3.y,
	                     &o->caras[o->numcaras].v3.z);
    	o->numcaras++;
    }
    fclose (f);
    return 1;
}

void AnimarMalla3D (struct objeto *o)
{
	int i;
	double x,y,z,xr,yr,zr,alpha;
	double rot[3][3];
	int px1,px2,py1,py2,px3,py3,ang=0;
	double wx,wy,wz;
	struct objeto or;

	/* Para detectar tecla pulsada dentro de la ventana de texto. */
    HANDLE hStdin; 
    DWORD cNumRead; 
    INPUT_RECORD irInBuf; 
 
    // Get the standard input handle. 
    hStdin = GetStdHandle(STD_INPUT_HANDLE); 
 
    // Enable the window and mouse input events. 
    SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT);
    
    printf ("Presione la tecla ESC para cerrar la ventana grafica . . .\n");
 
    while(1)
    {
    	wx=ang*3.141592654/180;
    	wz=wy=wx;

		/* Creación de la matriz de rotación 3D: se rota un ángulo en cada uno
		de los tres ejes X,Y,Z */
    	rot[0][0]=cos(wy)*cos(wz);
		rot[0][1]=cos(wy)*sin(wz);
		rot[0][2]=-sin(wy);
    	rot[1][0]=sin(wx)*sin(wy)*cos(wz)-cos(wx)*sin(wz);
		rot[1][1]=sin(wx)*sin(wy)*sin(wz)+cos(wx)*cos(wz);
		rot[1][2]=sin(wx)*cos(wy);
    	rot[2][0]=cos(wx)*sin(wy)*cos(wz)+sin(wx)*sin(wz);
		rot[2][1]=cos(wx)*sin(wy)*sin(wz)-sin(wx)*cos(wz);
		rot[2][2]=cos(wx)*cos(wy);

		Borrar();

		/* Rotar todos los puntos del objeto */
		or.numcaras=o->numcaras;
		for (i=0;i<o->numcaras;i++)
		{
				x=o->caras[i].v1.x;
				y=o->caras[i].v1.y;
				z=o->caras[i].v1.z;

				or.caras[i].v1.x=rot[0][0]*x+rot[0][1]*y+rot[0][2]*z;				
				or.caras[i].v1.y=rot[1][0]*x+rot[1][1]*y+rot[1][2]*z;				
				or.caras[i].v1.z=rot[2][0]*x+rot[2][1]*y+rot[2][2]*z;				
			
				x=o->caras[i].v2.x;
				y=o->caras[i].v2.y;
				z=o->caras[i].v2.z;

				or.caras[i].v2.x=rot[0][0]*x+rot[0][1]*y+rot[0][2]*z;				
				or.caras[i].v2.y=rot[1][0]*x+rot[1][1]*y+rot[1][2]*z;				
				or.caras[i].v2.z=rot[2][0]*x+rot[2][1]*y+rot[2][2]*z;				
			
				x=o->caras[i].v3.x;
				y=o->caras[i].v3.y;
				z=o->caras[i].v3.z;

				or.caras[i].v3.x=rot[0][0]*x+rot[0][1]*y+rot[0][2]*z;				
				or.caras[i].v3.y=rot[1][0]*x+rot[1][1]*y+rot[1][2]*z;				
				or.caras[i].v3.z=rot[2][0]*x+rot[2][1]*y+rot[2][2]*z;				
		}

		/* Ordenar los triángulos de más lejano a más cercano */
		qsort (or.caras, or.numcaras, sizeof(struct triang), compara_triang);

		/* Dibujar triangulos de más lejano a más cercano */
		for (i=0;i<or.numcaras;i++)
		{
			xr=or.caras[i].v1.x;
			yr=or.caras[i].v1.y;
			zr=or.caras[i].v1.z;
			alpha=(zr+250)/(zr-PVZ);
			px1=xr+alpha*(PVX-xr);
			py1=yr+alpha*(PVY-yr);

			xr=or.caras[i].v2.x;
			yr=or.caras[i].v2.y;
			zr=or.caras[i].v2.z;
			alpha=(zr+250)/(zr-PVZ);
			px2=xr+alpha*(PVX-xr);
			py2=yr+alpha*(PVY-yr);

			xr=or.caras[i].v3.x;
			yr=or.caras[i].v3.y;
			zr=or.caras[i].v3.z;
			alpha=(zr+250)/(zr-PVZ);
			px3=xr+alpha*(PVX-xr);
			py3=yr+alpha*(PVY-yr);
			
			Triangulo (px1,py1,px2,py2,px3,py3,BLANCO,AZUL);
			/*Linea (px1,py1,px2,py2,BLANCO);
			Linea (px2,py2,px3,py3,BLANCO);
			Linea (px3,py3,px1,py1,BLANCO);*/
		}
				
		ang=(ang+1)%360;
		Refrescar();
		if (or.numcaras<1000)
		  Sleep((1000-or.numcaras)/500);
		
		PeekConsoleInput(hStdin, &irInBuf, 1, &cNumRead);
		if (cNumRead==1)
		{
			ReadConsoleInput(hStdin, &irInBuf, 1, &cNumRead);
			if (irInBuf.EventType==KEY_EVENT)
				if (irInBuf.Event.KeyEvent.wVirtualKeyCode==VK_ESCAPE)
					break;
		}
    }
}

int compara_triang (const void *s1, const void *s2)
{
	struct triang *t1,*t2;
	
	t1=(struct triang *)s1;
	t2=(struct triang *)s2;
	
	if (t1->v1.z + t1->v2.z + t1->v3.z >= t2->v1.z + t2->v2.z + t2->v3.z )
  		return -1;
   	else
   		return 1;
}
