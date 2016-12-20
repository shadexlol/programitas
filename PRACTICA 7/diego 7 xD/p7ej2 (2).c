#include <stdio.h>

int main()
{
	int i;
	short a,b,c;
	FILE *f;

	f=fopen("memoria.txt","rt");
	if (f==NULL)
	{
		printf("ERROR! No puedo abrir el fichero.\n");
	}
	else
	{
		fscanf (f, "%hd %hd %hd ",&a,&b,&c);
		printf("%4.4x\n%4.4x\n%4.4x\n",a,b,c);
	}
		
/*		fscanf (f, "%4d%4d%4d%4d",&a,&b,&c,&d);
		printf("%4.4x\n%4.4x\n%4.4x\n%4.4x\n",a,b,c,d);
*/

		fclose(f);	
}
