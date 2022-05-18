#include <stdio.h>
#include <string.h>

struct info
{
	char *direccionMemoria;
	int longitudTexto;
};

char *carga(int*);
struct info busca (char *, int, char);

int main()
{
	int tamanio;
	char texto[1000];
	char caracter;
	info nuevoStruct;
	
	
	strcpy(texto,carga(&tamanio));
	//printf("%s",texto);
	printf("Ingrese un caracter a buscar \n");
	caracter=getchar();
	nuevoStruct=busca(texto,tamanio,caracter);
	
	printf("%s \nLONGITUD DEL TEXTO MOSTRADO %i CARACTERES",nuevoStruct.direccionMemoria,nuevoStruct.longitudTexto);
	
}

struct info busca (char * pt, int tam, char car)
{
	char *dirMem;
	int longText;
	info nStruct;
	int i;
	
	if(strchr(pt, car)!=NULL)
	{
		dirMem=strchr(pt, car);
	}
	else if(strchr(pt, car)==NULL)
	{
		printf("Caracter no encontrado \n");
	}
	
	nStruct.longitudTexto=strlen(dirMem);
	nStruct.direccionMemoria=dirMem;
	return nStruct;
}

char *carga(int* tam)
{
	char texto[1000];
	char *p;
	printf("Ingrese texto \n");
	gets(texto);
	p=texto;
	return p;
}
