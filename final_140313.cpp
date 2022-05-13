#include <stdio.h>
#include <string.h>

struct modif
{
	char textoMod[1000];
	int cantidadReemplazos;
};

char* carga(int*);
struct modif * reemplaza (char *, int, char, char);

int main()
{
	char* texto;
	int tamanio;

	texto=carga(&tamanio);
	
	printf("%s %i",texto,tamanio);
	
	
	return 0;
}



char* carga(int* tam)
{
	char texto[1000];
	printf("Ingrese un texto \n");
	gets(texto);
	*tam=strlen(texto);
	return texto;
}
