#include<iostream>
using namespace std;

//int cont=0;
long long int N;
//long long int A[100000];

void merge(long long int A[],long long int start, long long int mid,long long int end){
	
	
	
	long long int p=start,q=mid+1;
	
	long long int Arr[end-start+1],k=0;
	
	for(long long int i=start;i<=end;i++){
		if(p > mid){
			//cont++;
			Arr[k++] = A[q++];
			//cout<<"-> "<<k<<" - "<<q<<endl;
		}
		else if(q >end){
			//cont++;
			Arr[k++] = A[p++];
			//cout<<"-> "<<k<<" - "<<q<<endl;
		}
		else if(A[p] < A[q]){
			//cont++;
			Arr[k++] = A[p++];
			//cout<<"-> "<<k<<" - "<<q<<endl;
		}else{
			//cont++;
			Arr[k++] = A[q++];
			//cout<<"-> "<<k<<" - "<<q<<endl;
		}
	}
	//for(int i=0;i<3;i++){
	//		cout<<"-------<   "<<Arr[i]<<endl;
	//}
	
	for(long long int p=0; p<k;++p){
		A[start++] = Arr[p];
	}
	
}

merge_sorted(long long int A[], long long int start, long long int end){
	
	if(end > start){
		
		long long int mid = (start + end)/2;
		
		merge_sorted(A,start,mid);
		
		merge_sorted(A,mid+1,end);
		
		merge(A,start,mid,end);	
	}	
}

int main(){
	
	//int A[100] = {7,9,8,10,11,3,4,6,7,10};
	
	cin>>N;
	
	long long int A[N];
	
	for(long long int i=0;i<N;++i){
		cin>>A[i];
	}
	
	merge_sorted(A,0,N);
	
	for(long long int i=0;i<N;i++){
		cout<<"----- > "<<A[i]<<endl;
	}
	
	
	//cout<<"# ITERACIONES "<<cont<<endl;
}
