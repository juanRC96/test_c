#include <stdio.h>
#include <string.h>
#include<iostream>

struct Usuario{
	char cod_usu[8];
	char nom_usu[80];
	char password[30];
	char mail[100];
	int accion;
};

int carga_usuarios(struct Usuario*);
char* carga_caract_no_permitidos();
void valida_claves_usuarios(struct Usuario*,int,char*);
int valida_clave(char*,char*);


int main()
{
	char opc;
	Usuario users[100];
	Usuario *pu;
	pu = &users[0];
	
	int i=0;
	int cant;
	
	cant=carga_usuarios(pu);
	char* pc = carga_caract_no_permitidos();
	valida_claves_usuarios(pu,cant,pc);
	
	//IMPRESION DE STRUCTURE
	for(i;i<cant;i++)
	{
		printf("Codigo de usuario: %s \n",users[i].cod_usu);
		printf("Nombre de usuario: %s \n",users[i].nom_usu);
		printf("Contrasena: %s \n",users[i].password);
		printf("Mail: %s \n",users[i].mail);
		printf("Accion: %i \n",users[i].accion);
		i++;
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

void valida_claves_usuarios(struct Usuario *pu,int cantidad,char *pc)
{
	int i;
	int j;
	
	
	for(i=0;i<cantidad;i++)
	{
		//longitud minima y maxima de contrasena
		if(strlen(pu[i].password)>6 && strlen(pu[i].password)<30)
		{
			for(j=0;j<strlen(pc);j++)
			{
		 	//strchr devuelve direccion de puntero si encuentra el caracter, caso contrario es NULL
			if((strchr(pu[i].password, pc[j])) != NULL)
			{
				//las claves que deben ser cambiadas se le asigna 1 en accion
				pu[i].accion=1;
			}
			j++;
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
	char cont;
	int i=0;
	
	printf("Carga de caracteres no permitidos para contrasenas \n");
	
	cont='s';
		
		do{
			printf("Ingrese caracter no valido \n");
			caracteres[i]=getchar();
			i++;
			printf("Desea ingresar otro caracter? s/n");
			cont=getchar();
			getchar();
				
		}while(cont=='s');
		
	p = &caracteres[0];	
	
	return p;
}


int carga_usuarios(struct Usuario *p)
{
	char cont;
	int i=0;
	
	printf("Carga de usuarios \n");
	
	cont='s';
		
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
			printf("Desea ingresar otro alumno? s/n");
			cont=getchar();
			getchar();
				
		}while(cont=='s');
			
	return i;
}
