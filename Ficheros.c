#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 //   DECLARACION DE ESTRUCTURA

struct alum {
	char nombre[20];
	int edad;
	float peso;
	float estatura;
	float imc;
	//char salud[30];
};

//Prototipo de funcion
void cleanBuffIn(void);
void escribir_fichero (struct alum*,int);
int leer_fichero (struct alum*);


//Funcion Main

int main()
{
	int i,cantidad;
	struct alum *ptr;
	
	printf("Numero de alumos:");
	scanf("%d",&cantidad);
	struct alum alumno[cantidad];
	
	for(i=0;i<cantidad;i++)
	{
		printf("\nDame el nombre del alumno #%d ",i+1);
		cleanBuffIn();
		gets(alumno[i].nombre);
		cleanBuffIn();
		printf("\nDame la edad del alumno:");
		cleanBuffIn();
		scanf("%d",&alumno[i].edad);
		
		printf("\nDame el peso del alumno:");
		cleanBuffIn();
		scanf("%f",&alumno[i].peso);
		
		printf("\nDame la estatura del alumno:");
		cleanBuffIn();
		scanf("%f",&alumno[i].estatura);
		
		alumno[i].imc = alumno[i].peso / (alumno[i].estatura*alumno[i].estatura);
		
		/*if(alumno[i].imc < 18.5)
			char str[]"Bajo de peso" = alumno[i].salud;
		if(alumno[i].imc >= 18.5 && alumno[i].imc <= 24.9)
			alumno[i].salud = "Peso normal";
		if(alumno[i].imc > 24.9 && alumno[i].imc <= 29.9)
			alumno[i].salud = "Sobrepeso";
		if(alumno[i].imc < 29.9)
			alumno[i].salud = "Obesidad";*/
			
			
	}
	
	ptr = alumno;
	escribir_fichero (ptr,cantidad);
	
		
	/*for(i=0;i<cantidad;i++)
	{
		printf("\n Nombre del alumno (%d): %s",i+1,alumno[i].nombre);
		printf("\n Edad: %d",alumno[i].edad);
		printf("\n Peso %.2f",alumno[i].peso);	
		printf("\n Estatura %.2f",alumno[i].estatura);
		printf("\n Indice de masa corporal %.2f",alumno[i].imc);
	}*/		
	
	return 0;
}

void escribir_fichero(struct alum *pt,int cantidad)
{
	FILE *fich;
	int i;
	
	if ((fich = fopen("fichreg.dat", "wb")) == NULL)
	{
		puts("Error en apertura de archivo");
		exit(0);
	}
	else
	{
		for(i=0;i<cantidad;i++)
			fwrite(pt, sizeof(*pt), 1, fich);
	}
	
	fread (pt, sizeof(*pt), 1, fich);
  	while (!feof(fich))
  	{					
  		//fread (&r, sizeof(r), 1, fich);				//PROPUESTA DE MODIFICACION
  		//if(feof(fich)!=0) break;						//PROPUESTA DE MODIFICACION
  		printf ("Nombre: %s\nEdad: %d%\nEstatura: %.2f\nPeso: %.2f\nIMC: %.2f\n" , pt->nombre, pt->edad, pt->estatura, pt->peso ,pt->imc);
  		fread (pt, sizeof(*pt), 1, fich);
  	}	
}


void cleanBuffIn(void){     /*FUNCION PARA LIMPIAR EL BUFFER DE ENTRADA EN SUSTITUCION DE fflush(stdin)*/
	int ch;
	while ((ch = fgetc(stdin)) != EOF)  /* Brinca o descarta todos los caracteres de stdin, */
	{                                   /* hasta que se encuentra con EOF, llegado al final del buffer.*/
	  if( ch == '\n' ) break;           /* o si encuentra un salto de linea */
	}
}
