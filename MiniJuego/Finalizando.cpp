#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

using namespace std;

int main(){
	
	system ("color 4D");
	
	void borrarFichero();
	int IngreseDificultad();
	int jugarPartida(int numvidas);
	void agregarRecord(int numRecord);
	void verRecord();
	void Color(int x);
	bool verificarNumero(char num[]);
	
    
	bool vida = false;
	
    char ffin = 's';  // condicion del do-while
    int numVida,numRecord;  // variables primitivas
	char op[10],lis[10];
	
	
	printf("\t\t\tMENU DEL JUEGO\n");
	
	
	do{
		
		
	
    printf("\t#################################################\n");
	printf("\t#\t\t\t\t\t\t#\n");
	printf("\t#\t\t1.Jugar\t\t\t\t#\n");
	printf("\t#\t\t2.Records\t\t\t#\n");
	printf("\t#\t\t3.Configuracion\t\t\t#\n");
	printf("\t#\t\t4.Salir\t\t\t\t#\n");
	printf("\t#\t\t\t\t\t\t#\n");
	printf("\t#################################################\n\n");
	bool duda;
	printf("INGRESE OPCION :\n");
	
	do{ // Verifica que ingrese un numero necesariamente y sus parametros
	
	duda = false;
	scanf("%s",&op);
	
	
	if(verificarNumero(op)){duda = true;}
	
	}while(atoi(op)<1 || atoi(op)>4 || duda==false);
	
	
	
	
	
	
	if(atoi(op) == 1){system("cls");
	
	if(vida == false){ numVida = 3;} // Numero de vida por defecto .... 3
	
	
	
	numRecord = jugarPartida(numVida);
	
	if(numRecord > 0){agregarRecord(numRecord);}

	}
	
	
	if(atoi(op) == 2){system("cls");verRecord();}
	
	if(atoi(op) == 3){system("cls");system ("color 1A");printf("CONFIGURACIONES :\t\t (Aprete 4 para salir al menu principal)\n\n");printf("1.Elije la dificultad de juego\n2.Restaurar cambios\n3.Eliminar historial de records\n\n");
	printf("Opcion :\n");
	
	do{
	
	duda = false;
	scanf("%s",&lis);
	
	
	if(verificarNumero(lis)){duda = true;}
	
	}while(atoi(lis)<1 || atoi(lis)>4 || duda==false );
	
	if(atoi(lis) == 1){system("cls");vida = true; numVida = IngreseDificultad();}
	system("cls");
	if(atoi(lis) == 2){vida = false;}
	if(atoi(lis) == 3){borrarFichero(); printf("!!!!Formateo de records completado !!!!\n\n");}
	if(atoi(lis) == 4){continue;}
	
	
	}
	
	if(atoi(op) == 4){system("cls"); ffin = 'n'; }
	
	
	
	

}while(ffin == 's');
	
	return 0;

}

//######################################################################################

int IngreseDificultad(){
system ("color 1A");	
int dif,vida;
printf("DIFICULTAD :\n");
printf("1.Facil(6 vidas)\n2.Medio(4 vidas)\n3.Dificil(2 vidas)\n");
scanf("%d",&dif);
if(dif == 1){vida = 6; }
if(dif == 2){vida = 4; }
if(dif == 3){vida = 2; }

return vida;
}

//###########################################################################################################

int jugarPartida(int numvidas){
    
    bool verificarNumero(char num[]);
    
    system ("color 4D");
	int numClave, cont = 0;
	char num[10];
	
	bool verificando = false;
	
	srand(time(NULL));
	
	numClave = 1 + rand() % ((20+1)-1);;
	
	bool salirBucle=true;
	
	do{
		
		cont++;
		
		do{
		
		
		if(salirBucle==false){printf("\n\n!!!Dato invalido!!!\n\n");}
		
	
		
		salirBucle = false;
	
		printf("-Ingrese numero a adivinar\t-Aprete -2 para reiniciar partida\n\n-Aprete -1 para salir al menu principal\n\nNumero :");
		scanf("%s",&num);
		
		salirBucle = verificarNumero(num);
		
	   }while(salirBucle == false);
	   
	  	
		
		if(atoi(num) == 0){cont = 0;}
		if(atoi(num) == -1){cont=0; break;}
		
	    
		
		
		if(atoi(num) == -2){printf("!!!!!!!!!!!!!!!Partida Reiniciada!!!!!!!!!!!!!!!!!\n\n");
		printf("Numero de vida : %d\n\n",numvidas);cont=0;}
			
			
		
		
		
		if(atoi(num) == numClave){
			
			numvidas = numvidas - 10;
		    
			printf("-------------------------------------------------------------------------\n");
			printf("!!!!!!!!!!!!!! FELICITACIONES USTED ADIVINO DICHO NUMERO !!!!!!!!!!!!!!\n\n");
			printf("\tDato : Acerto en %d intentos\n",cont);
			printf("--------------------------------------------------------------------------\n");
			
			verificando = true;
		    return cont;
		
		}else{
			
			if(cont != numvidas){
				
				if(numClave > atoi(num) && atoi(num) != -2){
				
				printf("----> DATO : (NUMCLAVE > NUMERO) <----\n\n");
				printf("--------------------------------------\n\n");
				
			    }else{
				
				if(atoi(num) != -2){
				
				printf("----> DATO : (NUMCLAVE < NUMERO) <----\n\n");
				printf("--------------------------------------\n\n");}
			}		
				
				
			}
			
		
			
		   
			
		}
			
		
	
		
		
	}while(cont < numvidas);
	
		
	
	if( verificando == false && atoi(num) != -1){
		
		printf("\n\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! GAME OVER !!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n\a\a");
		printf("\t\t(>_<) (>_<)(>_<) (>_<)(>_<) (>_<)(>_<) (>_<)(>_<)\n\n");
		
		return 0;
			
	}
	
	

	
}

//###########################################################################################################

void agregarRecord(int numRecord){
	
	
FILE* fp;

fp = fopen("Jaime.txt","a"); //intenta abrir el archivo en modo de lectura/escritura
	
if(fp == NULL){fp = fopen("Jaime.txt","w"); }//crea el archivo en caso de no existir

fprintf(fp,"%d\n",numRecord);
fclose(fp);
                                             //fclose(fp);
}
    	
//########################################################################################################### 


void verRecord(){
	
	
	
	

system ("color 9A");

printf("########################## RECORDS ###############################\n\n");
	
void ordenarNumero(int lon, int arreglo[]);	

FILE *fp;
int numRecord;	
int f=0;
fp = fopen("Jaime.txt","r");
int i=0,cont=0;

if(fp == NULL)
	{
	   printf("!!!!!!!!!!!!!!!!!!!!!!HISTORIAL BORRADO !!!!!!!!!!!!!!!!!!!!\n\n\a");               //	fp = fopen("Alumnos.txt","w"); //crea el archivo en caso de no existir
		
	} 

	
	
i=fscanf(fp,"%d\n",&numRecord);

while(i != EOF){
	
cont++;
	
	
i=fscanf(fp,"%d\n",&numRecord);
	
}

int arreglo[cont];
rewind(fp);

i=fscanf(fp,"%d\n",&numRecord);

while(i != EOF){
	
	arreglo[f]=numRecord;

i=fscanf(fp,"%d\n",&numRecord);

f++;

}

if(cont == 0){printf("!!!!!!!!!!!!!!!!!!!!!!HISTORIAL BORRADO !!!!!!!!!!!!!!!!!!!!\n\n\a");}else{
ordenarNumero(cont,arreglo);}

fclose(fp);

}

//###########################################################################################################

/*void Color(int X){

SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X); 
} */

//###########################################################################################################
void ordenarNumero(int lon,int arreglo[]){
	
	
	int temp;
	
	for(int i=0;i<lon;i++){
		for(int j=0;j<lon-1;j++){
			if(arreglo[j]>arreglo[j+1]){
				
				temp = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1]= temp;
				
				
				
			}
		}
	}
	
	for(int i=0;i<lon;i++) printf("\t\t\tIntentos : %d\n",arreglo[i]);
}

//###########################################################################################################

void borrarFichero()
{

remove("Jaime.txt");
}

//###########################################################################################################

bool verificarNumero(char num[]){


if( atoi(num) == 0 ){return false;}else{return true;}

}









