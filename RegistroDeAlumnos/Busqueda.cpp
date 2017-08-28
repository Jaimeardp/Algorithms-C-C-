#include<stdio.h>
#include "Busqueda.h"
#include "Alumno.h"
#include "Docente.h"
#include "Curso.h"

void buscarA(int cod){
	FILE * f;
	f = fopen("tblAlumno.dat","rb");
	alu a;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(alu),1,f);

	while(!feof(f)){	
    	
    	if(a.cod == cod) printf("NOMBRE ALUMNO : %s ",a.nom);
    
		fread(&a,sizeof(alu),1,f);
			
	}
	fclose(f);
}

void buscarD(int cod){
	FILE * f;
	f = fopen("tblDocente.dat","rb");
	doc a;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(alu),1,f);

	while(!feof(f)){	
    	
    	if(a.cod == cod) printf("NOMBRE DOCENTE : %s ",a.nom);
    
		fread(&a,sizeof(alu),1,f);
			
	}
	fclose(f);
}
void buscarC(int cod){
	FILE * f;
	f = fopen("tblCurso.dat","rb");
	cur a;
	fseek(f,0L,SEEK_SET);
	fread(&a,sizeof(alu),1,f);

	while(!feof(f)){	
    	
    	if(a.cod == cod) printf("NOMBRE DE CURSO : %s ",a.nom);
    
		fread(&a,sizeof(alu),1,f);
			
	}
	fclose(f);
}

