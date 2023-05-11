#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct tab
{   char cadena[25];
    int  alfa;
};

char * ingresa_cadena();
struct tab* forma_tabla(char *, int *filas);
void busca_muestra(int longi, struct tab *, int filas);

//MAIN
int main()
{
	char *cadena;
	struct tab *cadenas;
	int filas;
	char cont;
	int cantPalabras;
	
	printf("Ingreso de cadenas \n");
	while(cont!='n')
	{
		cadena = ingresa_cadena();
		cadenas = forma_tabla(cadena, &filas);
		printf("Desea ingresar otra? s/n \n");
		scanf(" %c",&cont);
		while (getchar() != '\n');
	}
	
	for(int i=0;i<=filas;i++)
	{
		printf("La cadena %i: %s, tiene %d letras \n",i,cadenas[i].cadena,cadenas[i].alfa);
	}
	

	printf("Buscar cadenas por cantidad de letras \n");
	printf("Ingresa la cantidad de letras que debe tener la cadena: \n");
	scanf(" %i",&cantPalabras);
	
	busca_muestra(cantPalabras, cadenas, filas);
		
}

//BUSCA MUESTRA
void busca_muestra(int longi, struct tab * cadenas, int filas)
{
	int j=0;
	
	printf("Las cadenas que tienen %i letras son: \n",longi);
	while(j<=filas)
	{
		if(cadenas[j].alfa==longi)
		{
			printf("La cadena %i: %s\n",j,cadenas[j].cadena);
		}
		j++;
	}
}

//FORMA TABLA
struct tab* forma_tabla(char *cadena, int *filas)
{
	static struct tab cadenas[100];
	static int i;
	int j=0;
	int contadorLetras=0;
	
	strcpy(cadenas[i].cadena,cadena);
	
	while(cadena[j]!='\0')
	{
		if(isalpha(cadena[j]))
		{
			contadorLetras++;
		}
		j++;
	}
	
	cadenas[i].alfa=contadorLetras;
	
	*filas=i;
	i++;
	return cadenas;
}

//INGRESA CADENA
char * ingresa_cadena()
{
	static char cadena[25];
	printf("Ingrese una cadena \n");
	fgets(cadena, 25, stdin);
	return cadena;
}
