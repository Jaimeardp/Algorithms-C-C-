#include<stdio.h>
#include <fstream>
#include <iostream>
#include "Curso.h"

using namespace std;
void createCurso(){
	//Var required for the struct alumno
	//struct alumno al;
	cur dc;
	FILE *f;
	f =fopen("tblCurso.dat","ab");
	if(f == NULL) printf("File not found");
	else
		dc.cod = contadorC("tblCurso.dat")+100;
		if(dc.cod == -1|| dc.cod == 0) dc.cod = 100;
		if(verificarC(dc.cod)){
			dc.cod = dc.cod +1;
		}
		printf("Name :");
		scanf("%s",dc.nom);
		printf("Creditos :");
		scanf("%d",&dc.cred);
	
		fwrite(&dc,sizeof(cur),1,f);
		
	fclose(f);
	
}

bool verificarC(int cod){
	FILE *f;
	f = fopen("tblCurso.dat","rb");
	cur a;
	while(fread(&a,sizeof(cur),1,f)){
		
		if(a.cod == cod){
			return true;
		}			
	}
	fclose(f);
	return false;	
}

void updateCurso(int cod){
	FILE *f,*fx;
	f = fopen("tblCurso.dat","rb");
	fx = fopen("tblAux.dat","wb");
	//struct alumno a;
	cur a;
	while(fread(&a,sizeof(cur),1,f)){
		
	
		if(a.cod == cod){
			printf("Codigo : %d \n",a.cod);
			printf("Nombre : %s \n",a.nom);
			printf("Edad : %d \n",a.cred);
			printf("\n");
			printf("-----UPDATE---------\n");
			printf("Ingrese Nombre : ");
			scanf("%s",a.nom);
			printf("Ingrese Cred : ");
			scanf("%d",&a.cred);
		}	
		fwrite(&a,sizeof(cur),1,fx);	
	}
	fclose(f);
	fclose(fx);
	
	fx=fopen("tblAux.dat","rb");
    f=fopen("tblCurso.dat","wb");
            
    while(fread(&a, sizeof(cur),1, fx)){
        fwrite(&a, sizeof(cur),1, f);
    }
	fclose(f);
	fclose(fx);
	remove("tblAux.dat");
}

void deleteCurso(int cod){   
    FILE *f, *fx;
    //struct alumno a;
    cur a;
    fx=fopen("tblAux.dat","wb"); // rb lectura wb escritura
    f=fopen("tblCurso.dat","rb");

    if(!f) printf("Oh! Ah ocurrido un fallo!");
    else{
        //Recibe los mismo parametros que fwrite
        while(fread(&a, sizeof(cur),1, f)){
            if (a.cod != cod) fwrite(&a, sizeof(cur),1, fx);   
        }
            
        fclose(f);
        fclose(fx);
            
        fx=fopen("tblAux.dat","rb");
        f=fopen("tblCurso.dat","wb");
            
        while(fread(&a, sizeof(cur),1, fx)){
            fwrite(&a, sizeof(cur),1, f);
        }
    }
    fclose(f);
    fclose(fx);
    remove("tblAux.dat");
}

void reporteCurso(){
	FILE * f;
	f = fopen("tblCurso.dat","rb");
	//struct alumno a;
	cur a;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(cur),1,f);

	while(!feof(f)){	
    	printf("%d ",a.cod);
    	printf("%s ",a.nom);
    	printf("%d ",a.cred);
    
		fread(&a,sizeof(cur),1,f);
		printf("\n");	
	}
	fclose(f);
}

int contadorC(char  *nom){
	int cont;
	//struct alumno a;
	cur a;
	FILE * f = fopen(nom,"rb");
	if(f == NULL) return -1;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(cur),1,f);
	cont = 0;
	while(!feof(f)){		
	cont++;   
	fread(&a,sizeof(cur),1,f);	
	}
	fclose(f);
	return cont;
}

void getFileC(){
	FILE *f;
	ofstream escribir;
	escribir.open("curso.txt");
	f = fopen("tblCurso.dat","rb");
	cur a;	
	fseek(f,0L,SEEK_SET);

	if(f == NULL)printf("No funciono");
	escribir<<"------------------TABLA ALUMNO------------\n";
	escribir<<"CODIGO  "<<"  NOMBRE       "<<"   CREDITOS   ";
	while(fread(&a,sizeof(cur),1,f)){
		
		escribir<<"\n";
		escribir<<a.cod << "          "<<a.nom <<"          "<<a.cred;
		escribir<<"\n";
	}
	fclose(f);
	escribir.close();		
}


