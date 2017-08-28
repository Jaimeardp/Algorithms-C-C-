#ifndef _Alumno_H_
#define _Alumno_H_

typedef struct alumno{
	int cod;
	char nom[50];
	int edad;
}alu;

typedef struct matriculaxAlum{
	int codCurso;
	int codAlumno;
}mxa;

void createAlumno();
void updateAlumno(int cod);
void deleteAlumno(int cod);
void reporteAlumno();
int contadorA(char  *nom);
void nuevoAluxCurso(int codigo);
void reporteMatricula();
void buscarA(int codigo);
bool verificarA(int);
void getFileA();

#endif _Alumno_H_
