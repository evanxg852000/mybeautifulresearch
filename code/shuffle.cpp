#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


void shuffle(char* array,int size){
	int times=rand() % 100 + 1 ; //rand number 0-100
	char temp;
	do{
		int left=rand()%size+1;
		int right=rand()%size+1;
		if(left!=right){
			temp=*(array+left);
			*(array+left)=*(array+right);
			*(array+right)=temp;
		}
	}while(times--);

	string str;
	for(int i=0;i<size;i++){
	    str= (i!=size-1)? " , " : " ." ;
		cout<<*array<<str;
		array++;
	}
	cout<<" "<<endl;
	
}

int main(int argc, char* argv[] ){
	srand(time(NULL));
	
	char array[]={'a','b','c','d','e','f','g','h','i','k'};
	shuffle(array,10);
	return 0;
} 
