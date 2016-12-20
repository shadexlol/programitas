#include <stdio.h>
#define TMEMORIA 15

int main()
{
	int i;
	short mem[TMEMORIA];
	FILE *f;

	f=fopen("resultados.txt","at+");
	if (f==NULL)
	{
		printf("ERROR! No puedo abrir el fichero.\n");
	}
	else
	{
		for(i=0;i<TMEMORIA;i++)
		{
			mem[i]=i;
		}
		for(i=0;i<TMEMORIA;i++)
		{
			fprintf(f,"%.4x\n",mem[i]);	
		}
		fclose(f);
	}
	
}
