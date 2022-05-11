#include <stdio.h>
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
void valida_claves_usuarios(struct usuario*,int,char*);
int valida_clave(char*,char*);


int main()
{
	char opc;
	Usuario users[100];
	Usuario *p;
	p = &users[0];
	
	int tamanio = carga_usuarios(p);
	
	for(int i=0;i<tamanio;i++)
	{
		printf("Codigo de usuario: %s \n",users[i].cod_usu);
		printf("Nombre de usuario: %s \n",users[i].nom_usu);
		printf("Contrasena: %s \n",users[i].password);
		printf("Mail: %s \n",users[i].mail);
	}

	return 0;
}

int carga_usuarios(struct Usuario *p)
{
	char cont;
	int i=0;

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
