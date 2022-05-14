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
	char car1;
	char car2;

	texto=carga(&tamanio);
	
	printf("Ingrese caracter a reemplazar \n");
	car1=getchar();
	getchar();
	printf("Ingrese caracter a agregar \n");
	car2=getchar();
	
	
	modif *pstructNueva = reemplaza (texto,tamanio,car1,car2);
	
	modif structNueva = *pstructNueva;

	printf("Texto modificado: %s  Cantidad de modificaciones: %i",structNueva.textoMod,structNueva.cantidadReemplazos);
	
	
	return 0;
}

struct modif *reemplaza (char *text, int tam, char car1, char car2)
{
	modif *p;
	int contMod=0;
	modif nuevaStruct;
	
	for(int i=0;i<tam;i++)
	{
		if(text[i]==car1)
		{
			text[i]=car2;
			contMod++;
		}
	}
	
	strcpy(nuevaStruct.textoMod, text);

	nuevaStruct.cantidadReemplazos=contMod;
	
	p=&nuevaStruct;
	
	return p;
}

char* carga(int* tam)
{
	char *p;
	char texto[1000];
	printf("Ingrese un texto \n");
	gets(texto);
	*tam=strlen(texto);
	p=&texto[0];
	return p;
}
