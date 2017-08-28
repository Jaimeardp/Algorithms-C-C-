#include<stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "Alumno.h"
#include "Docente.h"
#include "Curso.h"
#include "Busqueda.h"
using namespace std;
void almacen();
void menu(int);
int listCursos(int);
int cantidadAlumnos(int);
void getFile();
int main(){
	char s='s';
	do{
		
		
		int op;
		printf("Opcion 1 = WAREHAUSE \n");
		printf("Opcion 2 = REGISTRO DE PROFESOR \n");
		printf("Opcion 3 = MATRICULA DE ALUMNO \n");
		printf("Opcion 4 = REPORTE DE MATRICULAS \n");
		printf("Opcion 5 = REPORTE DE CURSOS LLEVADOS X PROFESORES \n");
		printf("Opcion 6 = REPORTE DE CANTIDAD DE ALUMNOS X PROFESOR");
	
		scanf("%d",&op);
		system("cls");
		
		if(op == 1) {
			almacen();// break;
		}
		if(op == 2){
			printf("REGISTRO DE UN PROFESOR A UN CURSO A ENSEÑAR\n\n\n");
			printf("TABLA DE CURSO\n");
			printf("-------------------\n");
			reporteCurso();
			printf("\n");
			printf("TABLA DE DOCENTE\n");
			printf("------------------\n");
			reporteDocente();
			int codigo;
			printf("\nCODIGO DE CURSO ----- PARA EL PROFESOR X : ");
			scanf("%d",&codigo);
			nuevoDocentexCurso(codigo); //break;
		}
		
		if(op == 3){
			printf("REGISTRO DE UN ALUMNO A UN CURSO A ESTUDIAR\n\n\n");
			printf("TABLA DE CURSO\n");
			printf("-------------------\n");
			reporteCurso();
			printf("\n");
			printf("TABLA DE ALUMNO\n");
			printf("------------------\n");
			reporteAlumno();
			int codigo;
			printf("\nCODIGO DE CURSO ----- PARA EL ALUMNO : ");
			scanf("%d",&codigo);
			nuevoAluxCurso(codigo); //break;
		}
		
		if(op == 4){
			reporteMatricula(); //break;
		}
		if(op == 5){
			reporteCursosXDocente(); //break;
		}
		if(op == 6){
			int cod;
			printf("TABLA DOCENTE\n");
			printf("---------------------------------------\n");
			reporteDocente();
			printf("---------------------------------------\n");
			printf("TABLA CURSO\n");
			printf("---------------------------------------\n");
			reporteCurso();
			printf("---------------------------------------\n");
			printf("TABLA REGISTRO\n");
			printf("---------------------------------------\n");
			reporteCursosXDocente();
			printf("---------------------------------------\n");
			printf("COD DOCENTE : ");
			scanf("%d",&cod);
			int codigo;
			codigo = listCursos(cod);
			
			if(codigo == -1) {
				printf("Docente Not Found");
				//break;
			}else{
				buscarD(cod);
				printf("CODIGO : %d CANTIDAD ALUMNOS : %d CURSO : %d ",cod,cantidadAlumnos(codigo),codigo);
				printf("---------------------------------------\n");
			}
				
			//break;
		}
		printf("\n");
		
		printf("DESEA CONTINUAR ? (S = SI, CUALQUIER OTRO CARACTER ES PARA SALIR)");
		scanf("%s",&s);
		system("cls");
		
	}while(s =='s');
	
}

int cantidadAlumnos(int cod){
	FILE * f; int cont=0;
	f = fopen("tblMatricula.dat","rb");
	if(f == NULL) return -1;
	mxa a;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(mxa),1,f);

	while(!feof(f)){	
    	
    	if(a.codCurso == cod){
    		cont++;
		}
		fread(&a,sizeof(mxa),1,f);
		printf("\n");	
	}
	fclose(f);
	return cont;
}

int listCursos(int cod){
	FILE * f;
	f = fopen("tblRegistro.dat","rb");
	if(f == NULL) return -1;
	int i = 0;
	rxd a;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(rxd),1,f);
	while(!feof(f)){	
  		if(a.codProfesor == cod) return a.codCurso;
  			
		fread(&a,sizeof(rxd),1,f);	
	}
	fclose(f);
	return -1;
}

void almacen(){
	int op,cod;
	printf("Opcion 1 = ALUMNO \n");
	printf("Opcion 2 = DOCENTE \n");
	printf("Opcion 3 = CURSO \n");
	scanf("%d",&op);
	menu(op);
}

void menu(int i){
	system("cls");
	int op,cod;
	printf("Elija una opcion\n");
	printf("1.ADD \n2.UPDATE \n3.DELETE\n4.REPORTE");
	scanf("%d",&op);
	if(i == 1){
		system("cls");
		//reporteAlumno();
		printf("---------------------------------------\n");
		if(op == 1) createAlumno();
		if(op == 2) {
			reporteAlumno();
			printf("Ingrese Codigo --- UPDATE");
			scanf("%d",&cod);
			updateAlumno(cod);
		}
		if(op== 3) {
			reporteAlumno();
			printf("Ingrese Codigo --- DELETE");
			scanf("%d",&cod);
			deleteAlumno(cod);
		}
		if(op == 4){
		getFileA(); reporteAlumno();} 
	}
	if(i == 2){
		system("cls");
		//reporteDocente();
		printf("---------------------------------------\n");
		if(op == 1) createDocente();
		if(op == 2) {
			printf("Ingrese Codigo --- UPDATE");
			scanf("%d",&cod);
			updateDocente(cod);
		}
		if(op== 3) {
			reporteDocente();
			printf("Ingrese Codigo --- DELETE");
			scanf("%d",&cod);
			deleteDocente(cod);
		}
		if(op == 4){
			getFileD();
			reporteDocente();
		} 
	}
	if(i == 3){
		system("cls");
		//reporteCurso();
		printf("---------------------------------------\n");
		if(op == 1) createCurso();
		if(op == 2) {
			printf("Ingrese Codigo --- UPDATE");
			scanf("%d",&cod);
			updateCurso(cod);
		}
		if(op== 3) {
			printf("Ingrese Codigo --- DELETE ");
			scanf("%d",&cod);
			deleteCurso(cod);
		}
		if(op == 4){
			getFileC();
			reporteCurso();
		} 
	}	
		
}



/*
	while(!feof(f)){	
  		
  		co = a.cod; ed = a.edad;
  		no = a.nom;
  		
	/*	printf("JAJAJAJAJAJJAJAJAJAJAJJAJAJAJAJ%d",a.cod);
		escribir<<"CODIGO"<<"  NOMBRE"<<"   EDAD";
		escribir<<co << " "<<no <<"  "<<ed;
		escribir<<"\n";*/
    
		//fread(&a,sizeof(alu),1,f);
			
	/*/*/

