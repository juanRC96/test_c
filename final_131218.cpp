#include <stdio.h>
#include <string.h>
#include <iostream>

struct Usuario{
	char cod_usu[8];
	char nom_usu[80];
	char password[30];
	char mail[100];
	int accion;
};

void carga_usuarios(struct Usuario*,int*);
char* carga_caract_no_permitidos();
void valida_claves_usuarios(struct Usuario*,int,char*,int);
void envia_mail(struct Usuario*,int);


int main()
{
	char opc;
	Usuario users[100];
	/*
	Usuario *pu;
	pu = &users[0];
	*/
	int cant;
	
	
	carga_usuarios(users,&cant);
	char* pc = carga_caract_no_permitidos();
	int tam = strlen(pc);
	valida_claves_usuarios(users,cant,pc,tam);
	envia_mail(users,cant);
	
	
	//IMPRESION DE STRUCTURE
	for(int i=0;i<cant;i++)
	{
		printf("Codigo de usuario: %s \n",users[i].cod_usu);
		printf("Nombre de usuario: %s \n",users[i].nom_usu);
		printf("Contrasena: %s \n",users[i].password);
		printf("Mail: %s \n",users[i].mail);
		printf("Accion: %i \n",users[i].accion);
	}
	/*
	IMPRESION DE CARACTERES NO VALIDOS
	while(pc[i]!='\0')
	{
		printf("%c \n",pc[i]);
		i++;
	}
	*/
	return 0;
}

void envia_mail(struct Usuario *pu,int cantidad)
{
	printf("Enviando mails... \n");
	
	for(int i=0;i<cantidad;i++)
	{
		if(pu[i].accion==1)
		{
			printf("ENVIAR MAIL A USUARIO %s SOLICITANDO CAMBIO DE CONTRASENA \n",pu[i].nom_usu);
		}
	}
}

void valida_claves_usuarios(struct Usuario *pu,int cantidad,char *pc,int tam)
{
	printf("Validando claves... \n");
	
	//asigno tamanio de pc(coleccion de caracteres no validos) para tener un limite para el for que lo recorre, podria enviar como parametro desde el main el tamanio (es lo mismo)
	//int tamanio = strlen(pc);
	
	for(int i=0;i<cantidad;i++)
	{
		//longitud minima y maxima de contrasena
		if((strlen(pu[i].password))>3 && (strlen(pu[i].password))<30)
		{
			for(int j=0;j<tam;j++)
			{
		 	//strchr devuelve direccion de puntero si encuentra el caracter, caso contrario es NULL
			if((strchr(pu[i].password, pc[j])) != NULL)
			{
				//las claves que deben ser cambiadas se le asigna 1 en accion
				pu[i].accion=1;
			}
			}
		}
		else
		{
			pu[i].accion=1;
		}
			
	}	
}

char* carga_caract_no_permitidos()
{
	char caracteres[50];
	char *p;
	int cont;
	int i=0;
	
	printf("Carga de caracteres no permitidos para contrasenas \n\n");
	
	cont='s';
		
		do{
			printf("Ingrese caracter no valido \n");
			caracteres[i]=getchar();
			i++;
			printf("Desea ingresar otro caracter? 0:No / 1:Si \n");
			scanf("%d",&cont);
			getchar();
				
		}while(cont==1);
		
	p = &caracteres[0];	
	
	return p;
}


void carga_usuarios(struct Usuario *p,int* cant)
{
	int cont;
	int i=0;
	
	printf("Carga de usuarios \n\n");
	
		do{
			printf("Ingrese codigo de usuario \n");
			gets(p[i].cod_usu);
			printf("Ingrese nombre de usuario \n");
			gets(p[i].nom_usu);
			printf("Ingrese contrasena \n");
			gets(p[i].password);
			printf("Ingrese mail \n");
			gets(p[i].mail);
			p[i].accion=0;
			i++;
			printf("Desea ingresar otro usuario? 0:No / 1:Si \n");
			scanf("%d",&cont);
			getchar();
				
		}while(cont==1);
		*cant=i;
		
}
