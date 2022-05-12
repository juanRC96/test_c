#include <stdio.h>
#include <string.h>

void carga(char*,int*);
void esVocal(char,int*);
int esConsonante(char);

int main()
{
	char texto[100];
	int cant;	
	
	printf ("Ingrese el texto: ");
	carga(texto,&cant);
	
	printf("texto: %s y cantidad de caracteres: %d",texto,cant);
	
	return 0;
}

//con esta funcion sobreescribo las variables definidas en main
void carga(char* texto, int* cant)
{
	gets(texto);
	*cant=strlen(texto);
}
