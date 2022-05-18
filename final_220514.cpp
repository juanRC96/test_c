#include <stdio.h>

struct datos
{
	char nom_usuario[20];
	char clave[20];
};

struct datos * carga (int *); 
struct datos * valida (char *, char *, struct datos *, int);
void  reemplaza  (struct datos *, char *);

int main()
{
	int tam;
	datos *pDatos;
	pDatos=carga(&tam);
	
	for(int i=0;i<tam;i++)
	{
		printf("Usuario: %s \n",pDatos->nom_usuario);
		printf("Contrasenia: %s \n",pDatos->clave);
		pDatos++;
	}
	
}

void  reemplaza  (struct datos *, char *)
{
	
}

struct datos * valida (char *, char *, struct datos *, int)
{
	
}

struct datos * carga (int * tamanio)
{
	struct datos colDatos[1000];   
	datos *pDatos;
	pDatos=colDatos;
	int continuar,contador;
	
	printf("Ingresar usuario? 0/1 \n");
    scanf("%i",&continuar);
	
	do
	{
    printf("Cargar usuario \n");
    printf("Ingrese nombre de usuario: \n");
    scanf("%s", pDatos->nom_usuario);
    printf("Ingrese clave de usuario: \n");
    scanf("%s", pDatos->clave);
    
    printf("Ingresar otro usuario? 0/1 \n");
    scanf("%i",&continuar);
    contador++;
    //incremento el puntero para acceder a la siguiente posicion de memoria
    pDatos++;
	}
	while(continuar==1);
	
	//ASIGNO TAMANIO DE COLECCION
	*tamanio=contador;
	
	//RETORNO EL PUNTERO AL INICIO DE LA COLECCION
	pDatos=&colDatos[0];
	return pDatos;	
}
