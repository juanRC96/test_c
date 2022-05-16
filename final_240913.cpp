#include <stdio.h>
#include <string.h>

struct palcalif { 
char pala[20];	/*palabra calificadora*/
int cantidad;	/*cantidad de veces que aparece en el texto*/
};

struct palcalif * carga_palabras(int*);
void carga_texto (char *, int *);

int main()
{
	char texto[100];
	int cantidad;
	
	carga_texto (texto,&cantidad);
	
	printf("%s %i",texto,cantidad);
	
}

void carga_texto(char *pt,int *pc)
{
	printf("Ingrese el texto \n");
	gets(pt);
	*pc=strlen(pt);

}
