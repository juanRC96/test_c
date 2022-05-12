#include <stdio.h>
#include <string.h>
#include <iostream>

void carga(char*,int*);
void esVocal(char,int*);
int esConsonante(char);

int main()
{
	char texto[100];
	int cant;
	
	char c;
	int vocal;
	int cons;
	
	int cantidadVocales=0;
	int cantidadConsonantes=0;
	
	printf ("Ingrese el texto: ");
	carga(texto,&cant);

	for(int i=0;i<cant;i++)
	{
		esVocal(texto[i],&vocal);
		if(vocal==1)
		{
			cantidadVocales++;
		}
		else if(vocal==0)
		{
			cons=esConsonante(texto[i]);
			if(cons==1)
			{
				cantidadConsonantes++;
			}
		}	
	}
	
	int porcVoc=(cantidadVocales*100)/cant;
	int porcCons=(cantidadConsonantes*100)/cant;
	
	printf("El texto: %s , tiene %d %% vocales y %d %% consonantes",texto,porcVoc,porcCons);
	
	return 0;
}

//con esta funcion retorno un 0 o 1
int esConsonante(char c)
{
	if(isalpha(c) && (c!='a' && c!='e' && c!='i' && c!='o' && c!='u'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//con esta funcion sobreescribo la variable vocal definida en main
void esVocal(char c,int* vocal)
{
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
	{
		*vocal=1;
	}
	else
	{
		*vocal=0;
	}
}

//con esta funcion sobreescribo las variables definidas en main
void carga(char* texto, int* cant)
{
	gets(texto);
	*cant=strlen(texto);
}
