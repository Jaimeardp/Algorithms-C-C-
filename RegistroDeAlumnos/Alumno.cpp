#include<stdio.h>
#include <fstream>
#include <iostream>
#include "Alumno.h"
#include "Busqueda.h"
using namespace std;

void createAlumno(){
	//Var required for the struct alumno
	alu al;
	FILE *f;
	f =fopen("tblAlumno.dat","ab");
	if(f == NULL) printf("File not found");
	else
		al.cod = contadorA("tblAlumno.dat");
		if(al.cod == -1|| al.cod == 0) al.cod = 0;
		if(verificarA(al.cod)){
			al.cod = al.cod +1;
		}
		printf("Name :");
		scanf("%s",al.nom);
		printf("Age :");
		scanf("%d",&al.edad);
	
		fwrite(&al,sizeof(alu),1,f);
		
	fclose(f);
	
}

bool verificarA(int cod){
	FILE *f;
	f = fopen("tblAlumno.dat","rb");
	alu a;
	while(fread(&a,sizeof(alu),1,f)){
		
		if(a.cod == cod){
			return true;
		}			
	}
	fclose(f);
	return false;	
}

void updateAlumno(int cod){
	FILE *f,*fx;
	f = fopen("tblAlumno.dat","rb");
	fx = fopen("tblAux.dat","wb");
	alu a;
	while(fread(&a,sizeof(alu),1,f)){
		
	
		if(a.cod == cod){
			printf("Codigo : %d \n",a.cod);
			printf("Nombre : %s \n",a.nom);
			printf("Edad : %d \n",a.edad);
			printf("\n");
			printf("-----UPDATE---------\n");
			printf("Ingrese Nombre : ");
			scanf("%s",a.nom);
			printf("Ingrese Edad : ");
			scanf("%d",&a.edad);
		}	
		fwrite(&a,sizeof(alu),1,fx);	
	}
	fclose(f);
	fclose(fx);
	
	fx=fopen("tblAux.dat","rb");
    f=fopen("tblAlumno.dat","wb");
            
    while(fread(&a, sizeof(alu),1, fx)){
        fwrite(&a, sizeof(alu),1, f);
    }
	fclose(f);
	fclose(fx);
	remove("tblAux.dat");
}

void deleteAlumno(int cod){   
    FILE *f, *fx;
    alu a;
    fx=fopen("tblAux.dat","wb"); // rb lectura wb escritura
    f=fopen("tblAlumno.dat","rb");

    if(!f) printf("Oh! Ah ocurrido un fallo!");
    else{
        //Recibe los mismo parametros que fwrite
        while(fread(&a, sizeof(alu),1, f)){
            if (a.cod != cod) fwrite(&a, sizeof(alu),1, fx);   
        }
            
        fclose(f);
        fclose(fx);
            
        fx=fopen("tblAux.dat","rb");
        f=fopen("tblAlumno.dat","wb");
            
        while(fread(&a, sizeof(alu),1, fx)){
            fwrite(&a, sizeof(alu),1, f);
        }
    }
    fclose(f);
    fclose(fx);
    remove("tblAux.dat");
}

void reporteAlumno(){
	FILE * f;
	f = fopen("tblAlumno.dat","rb");
	alu a;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(alu),1,f);

	while(!feof(f)){	
    	printf("CODIGO  %d ",a.cod);
    	printf("NOMBRE  %s ",a.nom);
    	printf("EDAD  %d ",a.edad);
    
		fread(&a,sizeof(alu),1,f);
		printf("\n");	
	}
	fclose(f);
}

int contadorA(char  *nom){
	int cont;
	alu a;
	FILE * f = fopen(nom,"rb");
	if(f == NULL) return -1;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(alu),1,f);
	cont = 0;
	while(!feof(f)){		
	cont++;   
	fread(&a,sizeof(alu),1,f);	
	}
	fclose(f);
	return cont;
}

void nuevoAluxCurso(int codigo){
	int cod;
	printf("-----------MATRICULA-----------");
	printf("CODIGO : ");
	scanf("%d",&cod);
	//struct matriculaxAlum mxa;
	mxa m;
	FILE *f;
	f =fopen("tblMatricula.dat","ab");
	if(f == NULL) printf("File not found");
	else

		m.codAlumno = cod;
		m.codCurso = codigo;
	
		fwrite(&m,sizeof(mxa),1,f);
		
	fclose(f);
}

void reporteMatricula(){
	FILE * f;
	f = fopen("tblMatricula.dat","rb");
	//struct alumno a;
	mxa a;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(mxa),1,f);

	while(!feof(f)){
		
		printf("CODIGO ALUMNO : %d  ",a.codAlumno);
		buscarA(a.codAlumno);
		printf("CODIGO CURSO : %d  ",a.codCurso);
		buscarC(a.codCurso);	
    
		fread(&a,sizeof(mxa),1,f);
		printf("\n");	
	}
	fclose(f);
}

void getFileA(){
	FILE *f;
	ofstream escribir;
	escribir.open("alumno.txt");
	f = fopen("tblAlumno.dat","rb");
	alu a;	
	fseek(f,0L,SEEK_SET);

	if(f == NULL)printf("No funciono");
	escribir<<"------------------TABLA ALUMNO------------\n";
	escribir<<"CODIGO  "<<"  NOMBRE       "<<"   EDAD   ";
	while(fread(&a,sizeof(alu),1,f)){
		
		escribir<<"\n";
		escribir<<a.cod << "          "<<a.nom <<"          "<<a.edad;
		escribir<<"\n";
	}
	fclose(f);
	escribir.close();		
}


