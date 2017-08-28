#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;
int cont=0;
int main(){
	
	long long int num;
	long long int max = 100000;
	
	ofstream escribir;
	
	escribir.open("randomn.txt");
	
	
	
	while(max != 0){
	
	
	cont++;
	num = rand() % 100000; 
	cout<<num << " ";
	escribir << num <<"\n";
	max--;
	}
	cout<<cont;
	escribir.close();	
	
}
