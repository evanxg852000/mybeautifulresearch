#include <iostream>
#include <iomanip>

using namespace std;

template<typename T> 
bool bsearch(T A[] ,T lookfor, int size, int &loc, int start=0 ,int end=0 ){
	if(start>end){
		return false;
	}
	end=(end==0)? size-1 : end;
	
	int middle=(start+end+1)/2;
	if(lookfor==A[middle]){
		loc=middle;
		return true;
	}
	else if(lookfor<A[middle]){
		return bsearch(A,lookfor,middle-1,loc,0,middle-1);
	}
	else {
		return bsearch(A,lookfor,middle-1,loc,middle+1,end);
	}
	
}

template<typename T>  
void sort(T &A,int size){
	for(int i=0; i<size; i++){
		for(int j=0;j<size;j++){
			if(A[i]<A[j]){
				swap(A[i],A[j]);
			}
		}
	}
}

template<class T>
void swap(T &l, T &r){
	T temp=l;
	l=r;
	r=temp;	
} 

template<typename T>
void show(T &A,int size){
	for(int i=0;i<size;i++)
		cout<<setw(3)<<A[i]<<" ";
	cout<<endl;
}

int main(int argc, char *argv[]){
	int a[10]={2,5,6,78,34,56,12,8,90,43};
	cout<<"Array Content:";show(a,10);
	sort(a,10);
	cout<<"Array Sorted: "; show(a,10);
	int lookfr,loc=0;
	
	cout<<"enter serach key "<<endl; cin>>lookfr;
	
	bool isfound = bsearch(a,lookfr,10,loc);
	if(isfound){
		cout<<"The value "<<lookfr<<" was found at "<<loc<<endl;
	}
	else{
		cout<<"The value "<<lookfr<<" was not found !"<<endl;
	}

	return (0);
}