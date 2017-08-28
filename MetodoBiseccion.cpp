#include<iostream>
#include<math.h>
using namespace std;

int main(){
	
    double f(double x);
    double f2(double x);
    double f1(double x);
	double a,b;
	double aux;
	
	cout<<"Ingrese intervalo"<<endl;
	
	cin>>a;
	cin>>b;
	int i=1;
	double c = (a + b ) / 2;
	
	
	
	do{
		
		c = (a + b ) / 2;
		
		cout<<i<<" "<<a<<"  "<<b<<" "<<c<<" "<<fabs((c - aux)/c)<<endl;
		i++;
		aux = c;
		
		
		
		if((f1(a) * f1(c)) >0){
			
			a = c;
			
		}else{
			
			b = c;
		
			
			
		}
		
	//	cout<<a<<"  "<<c<<" "<<b<<" "<<endl;
		
	
		
	}while( fabs(f1(c))  > 0.001); // fabs((c - aux)/c)
	
   cout<<"La respuestas ...."<<a<<" "<<b<<endl;
	
	return 0;
	
}

 double f(double x){
	
	//double y = pow(2.718281828,(-a))- log(a);
	double y;
	
	//y = x* sin(x) - 1;
	
	y = (pow(2.718281828,(x)) - 2);
	
    return	y;
	
}

double f1(double x){
	
	double y = x* sin(x) - 1;
	
	return y;
	
}

double f2(double x){
	
	double y = pow(2.718281828,(-x))- log(x);
	
	return y;
	
}
