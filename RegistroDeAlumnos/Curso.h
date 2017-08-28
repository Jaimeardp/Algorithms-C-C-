#ifndef _Curso_H_
#define _Curso_H_

typedef struct curso{
	int cod;
	char nom[50];
	int cred;
}cur;

void createCurso();
void updateCurso(int cod);
void deleteCurso(int cod);
void reporteCurso();
int contadorC(char  *nom);
void buscarC(int codigo);
bool verificarC(int);
void getFileC();
#endif _Curso_H_
