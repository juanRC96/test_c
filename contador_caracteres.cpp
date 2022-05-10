#include <stdio.h>
#include <string.h>
#include <iostream>

int cantNumeros(char*,int);
int cantVocales(char*,int);
int cantConsonantes(char*,int);

int esVocal(char);

int main()
{
	char cadena[100];
	char *p;
	int tamanio;
	int cantNum,cantVoc,cantCons;
	
	printf("Ingrese una cadena de caracteres \n");
	gets(cadena);
	tamanio=strlen(cadena);
	p = &cadena[0]; //asigno direccion de memoria del inicio del arreglo al puntero
	
	cantNum=cantNumeros(p,tamanio);
	cantVoc=cantVocales(p,tamanio); //envio puntero y tamanio de cadena
	cantCons=cantConsonantes(p,tamanio);
	
	printf("\nLa cadena ingresada es: %s \n\n",p);
	printf("Contiene %i numeros, %i vocales y %i consonantes \n",cantNum,cantVoc,cantCons);
	
	return 0;
	
}

//CONTADOR DE NUMEROS
int cantNumeros(char *p,int tamanio)
{
	int contador=0;
	
	for(int i=0;i<tamanio;i++)
	{
		if(p[i]=='1' || p[i]=='2' || p[i]=='3' || p[i]=='4' || p[i]=='5' || p[i]=='6' || p[i]=='7' || p[i]=='8' || p[i]=='9' || p[i]=='0')
		{
			contador++;
		}
	}
	return contador;
}

//CONTADOR DE VOCALES
int cantVocales(char *p,int tamanio)
{
	int contador=0;
	
	for(int i=0;i<tamanio;i++)
	{
		if(esVocal(p[i]))
		{
			contador++;
		}
	}
	return contador;
}

//CONTADOR DE CONSONANTES
int cantConsonantes(char *p,int tamanio)
{
	int contador=0;
	
	for(int i=0;i<tamanio;i++)
	{
		if(isalpha(p[i]) && !esVocal(p[i]))
		{
			contador++;
		}
	}
	return contador;
}

//VALIDAR SI ES VOCAL
int esVocal(char c)
{
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}
