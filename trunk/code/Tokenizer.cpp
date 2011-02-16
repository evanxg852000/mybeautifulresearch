/*
An attemp to write a string tokenizer for a parsing tool !
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


class Tokenizer{
public:
	Tokenizer(char delimiters[],int size);
	~Tokenizer();
	vector<string> Tokens(string source_code);

private:
	bool is_delimiter(char c);
	char *delimiters;
	int size_delimiter;

};

Tokenizer::Tokenizer(char delimiters[],int size){
	this->delimiters=delimiters;
	this->size_delimiter=size;
}

Tokenizer::~Tokenizer(){

}

vector<string> Tokenizer::Tokens(string source_code){
	vector<string> tokens;
	string token="";
	int code_number_character=source_code.size();
	int number_delimiters=12;
	string current;
	
	
	for(int i=0;i<code_number_character; i++){
		current=source_code[i];
		if(this->is_delimiter(source_code[i])){
			tokens.push_back(token);
			tokens.push_back(current);
			token="";
		}
		else{
			token +=source_code[i];
		}
		
	}
	
	return tokens;
}

bool Tokenizer::is_delimiter(char c){
	for(int i=0;i<this->size_delimiter;i++){
		if(this->delimiters[i]==c){
			return true;
		}			
	}
	return false;
}


int main(int argc, char *argv[]){
	char deli[]={' ','=','+','-','/','*','%',':','.','{','(',')',';'};

	Tokenizer t(deli,12);
	vector<string>tks=t.Tokens("function main( var ) {  b=a+2 ;  echo breg; } ");
	for(int i=0; i<tks.size();i++){
		cout<<i<<":"<<tks.at(i)<<endl;
	}
	

	return 0;
}