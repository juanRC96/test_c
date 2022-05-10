#include <stdio.h>
#include <string.h>

struct Alumno
{
	char alum[10];
	int nota[4];
};


int main()
{
	int i,j,k;
	int cant=0;
	int prom=0;
	int sum=0;
	struct Alumno alumnos[10];
	
	printf("Cuantos alumnos desea cargar? \n");
	scanf("%d",&cant);
	
	for(i=0; i<cant; i++)
    {
        printf("\nIngrese apellido: ");
        scanf("%s",&alumnos[i].alum);
        
        for(j=0;j<=2;j++)
        {
        	k=j+1;
        	printf("\nIngrese nota parcial %d: \n",k);
        	scanf("%d",&alumnos[i].nota[j]);
		}
        
    }
    printf("\nLos alumnos y sus notas promedio son: \n");
    	for(i=0; i<cant; i++)
    {
        printf("\n Alumno: %s , ",&alumnos[i].alum);
		for(j=0;j<=2;j++)
        {
        	sum+=alumnos[i].nota[j];
		}
		prom=sum/3;
		printf("nota promedio: %d ",prom);
		sum=0;

    }	 
	return 0;
}
