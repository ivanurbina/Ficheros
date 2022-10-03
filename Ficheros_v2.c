/*
	Nombre del archivo:    Ficheros_v2.c
	Version del programa:  Dev-C++ 5.11.
	Escuela:			   TecNM campus Chihuahua.
	Descripcion:           Calculo de IMC y uso de ficheros.
	Autor:      	       Ivan Urbina.
					       V 1.0
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Declaracion de estructura
typedef struct 
{
	char nombre[20];
	int edad;
	float peso;
	float estatura;
	float imc;
}Alumn_s;

int main()
{
	FILE *fich;		//Declaracion de fichero
	int i,size;
	Alumn_s alu,alu1;		//Variables de tipo Alumn_s
	
	printf("Numero de alumos:");
	scanf("%d",&size);
	
	if ((fich = fopen("Lista", "wb")) == NULL)		//Validacion de apertura de fichero
	{ 	
		printf ("Error en apertura del fichero para escritura\n");
		return 1;
	}
	else 
	{
		for (i = 0; i < size; i++ )		//For para lectura de datos
		{ 	
			printf("\nDame el nombre del alumno #%d ",i+1);
			fflush(stdin);
			gets(alu.nombre);
			
			printf("\nDame la edad del alumno:");
			fflush(stdin);
			scanf("%d",&alu.edad);
			
			printf("\nDame el peso del alumno:");
			fflush(stdin);
			scanf("%f",&alu.peso);
			
			printf("\nDame la estatura del alumno:");
			fflush(stdin);
			scanf("%f",&alu.estatura);
			
			alu.imc = alu.peso / (alu.estatura*alu.estatura);

			fwrite(&alu, sizeof(alu), 1, fich);		//Escritura de datos desde fichero
		}			
		fclose (fich);
	}	
	
	if ((fich = fopen("Lista", "rb")) == NULL)		//Validacion de apertura de fichero
	{ 	
		printf ( "Error en apertura del fichero para lectura \n " );
		return 1;
	}
	else
	{	
		printf ("\n Imprimendo datos del Fichero\n");
		fread (&alu1, sizeof(alu1), 1, fich);
		while (!feof(fich))
		{				
			//Impresion de datos
			
			printf ("Nombre: %s\nEdad: %d\nEstatura: %.2f\nPeso: %.2f\nIMC: %.2f\n" , alu1.nombre, alu1.edad, alu1.estatura, alu1.peso , alu1.imc);
			
			//Validaciones de los IMC
			
			if(alu1.imc < 18.5)
				puts("Bajo de peso");
				
			if(alu1.imc >= 18.5 && alu1.imc <= 24.9)
				puts("Peso normal");
			
			if(alu1.imc > 24.9 && alu1.imc <= 29.9)
				puts("Sobrepeso");
			
			if(alu1.imc > 29.9)
				puts("Obesidad");
			
			fread (&alu1, sizeof(alu1), 1, fich);		//Lectura de datos desde fichero
		}	
		fclose (fich);
	}
}
