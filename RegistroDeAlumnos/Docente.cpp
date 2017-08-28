#include<stdio.h>
#include <fstream>
#include <iostream>
#include "Docente.h"
#include "Busqueda.h"

using namespace std;

void createDocente(){
	//Var required for the struct alumno
	//struct alumno al;
	doc dc;
	FILE *f;
	f =fopen("tblDocente.dat","ab");
	if(f == NULL) printf("File not found");
	else
		dc.cod = contadorD("tblDocente.dat");
		if(dc.cod == -1|| dc.cod == 0) dc.cod = 0;
		if(verificarD(dc.cod)){
			dc.cod = dc.cod +1;
		}
		printf("Name :");
		scanf("%s",dc.nom);
		printf("DNI :");
		scanf("%d",&dc.dni);
	
		fwrite(&dc,sizeof(doc),1,f);
		
	fclose(f);
	
}

bool verificarD(int cod){
	FILE *f;
	f = fopen("tblDocente.dat","rb");
	doc a;
	while(fread(&a,sizeof(doc),1,f)){
		
		if(a.cod == cod){
			return true;
		}			
	}
	fclose(f);
	return false;	
}

void updateDocente(int cod){
	FILE *f,*fx;
	f = fopen("tblDocente.dat","rb");
	fx = fopen("tblAux.dat","wb");
	//struct alumno a;
	doc a;
	while(fread(&a,sizeof(doc),1,f)){
		
	
		if(a.cod == cod){
			printf("Codigo : %d \n",a.cod);
			printf("Nombre : %s \n",a.nom);
			printf("Edad : %d \n",a.dni);
			printf("\n");
			printf("-----UPDATE---------\n");
			printf("Ingrese Nombre : ");
			scanf("%s",a.nom);
			printf("Ingrese Edad : ");
			scanf("%d",&a.dni);
		}	
		fwrite(&a,sizeof(doc),1,fx);	
	}
	fclose(f);
	fclose(fx);
	
	fx=fopen("tblAux.dat","rb");
    f=fopen("tblDocente.dat","wb");
            
    while(fread(&a, sizeof(doc),1, fx)){
        fwrite(&a, sizeof(doc),1, f);
    }
	fclose(f);
	fclose(fx);
	remove("tblAux.dat");
}

void deleteDocente(int cod){   
    FILE *f, *fx;
    //struct alumno a;
    doc a;
    fx=fopen("tblAux.dat","wb"); // rb lectura wb escritura
    f=fopen("tblDocente.dat","rb");

    if(!f) printf("Oh! Ah ocurrido un fallo!");
    else{
        //Recibe los mismo parametros que fwrite
        while(fread(&a, sizeof(doc),1, f)){
            if (a.cod != cod) fwrite(&a, sizeof(doc),1, fx);   
        }
            
        fclose(f);
        fclose(fx);
            
        fx=fopen("tblAux.dat","rb");
        f=fopen("tblDocente.dat","wb");
            
        while(fread(&a, sizeof(doc),1, fx)){
            fwrite(&a, sizeof(doc),1, f);
        }
    }
    fclose(f);
    fclose(fx);
    remove("tblAux.dat");
}

void reporteDocente(){
	FILE * f;
	f = fopen("tblDocente.dat","rb");
	//struct alumno a;
	doc a;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(doc),1,f);

	while(!feof(f)){	
    	printf("CODIGO  %d ",a.cod);
    	printf("NOMBRE  %s ",a.nom);
    	printf("  DNI  %d ",a.dni);
    
		fread(&a,sizeof(doc),1,f);
		printf("\n");	
	}
	fclose(f);
}

int contadorD(char  *nom){
	int cont;
	//struct alumno a;
	doc a;
	FILE * f = fopen(nom,"rb");
	if(f == NULL) return -1;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(doc),1,f);
	cont = 0;
	while(!feof(f)){		
	cont++;   
	fread(&a,sizeof(doc),1,f);	
	}
	fclose(f);
	return cont;
}

void nuevoDocentexCurso(int codigo){
	int cod;
	printf("-----------REGISTRO DE CURSO-----------\n");
	printf("CODIGO DE PROFESOR : \n");
	scanf("%d",&cod);
	//struct matriculaxDoce mxd;
	rxd mxd;
	FILE *f;
	f =fopen("tblRegistro.dat","ab");
	if(f == NULL) printf("File not found");
	else

		mxd.codProfesor = cod;
		mxd.codCurso = codigo;
	
		fwrite(&mxd,sizeof(rxd),1,f);
		
	fclose(f);
}

void reporteCursosXDocente(){
	FILE * f;
	f = fopen("tblRegistro.dat","rb");
	if(f == NULL) return;
	rxd a;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(rxd),1,f);

	while(!feof(f)){	
    	printf("COD DOCENTE : %d ",a.codProfesor);
    	buscarD(a.codProfesor);
    	printf("COD CURSO : %d ",a.codCurso);
    	buscarC(a.codCurso);
    
		fread(&a,sizeof(rxd),1,f);
		printf("\n");	
	}
	fclose(f);
}

void getFileD(){
	FILE *f;
	ofstream escribir;
	escribir.open("docente.txt");
	f = fopen("tblDocente.dat","rb");
	doc a;	
	fseek(f,0L,SEEK_SET);

	if(f == NULL)printf("No funciono");
	escribir<<"------------------TABLA ALUMNO------------\n";
	escribir<<"CODIGO  "<<"  NOMBRE       "<<"   DNI   ";
	while(fread(&a,sizeof(doc),1,f)){
		
		escribir<<"\n";
		escribir<<a.cod << "          "<<a.nom <<"          "<<a.dni;
		escribir<<"\n";
	}
	fclose(f);
	escribir.close();		
}
