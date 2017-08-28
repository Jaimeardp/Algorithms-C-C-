#ifndef _Docente_H_
#define _Docente_H_

typedef struct docente{
	int cod;
	char nom[50];
	int dni;
}doc;

typedef struct matriculaxProf{
	int codProfesor;
	int codCurso;
}rxd;

void createDocente();
void updateDocente(int cod);
void deleteDocente(int cod);
void reporteDocente();
int contadorD(char  *nom);
void nuevoDocentexCurso(int codigo);
void reporteCursosXDocente();
void buscarD(int codigo);
bool verificarD(int);
void getFileD();

#endif _Docente_H_
