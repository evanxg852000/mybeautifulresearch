#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void reverse(string &);

int main(int argc, char *argv[]){
	if(argc !=2){
		cout<<"You need to specify the text file "<<endl;
		return (0);
	}
	
	fstream file(argv[1]);
	string content,line;
	
	if(file.is_open()){
		while(!file.eof()){
			getline(file,line);
			content+=line;
		}
		file.close();
	}
	reverse(content);
	cout<< "After reversing..."<<endl;
	cout<<content<<endl;
	return (0);
}

void reverse(string &content){
	vector<string> words;
	string word;
	for(int i=0;i<content.size();i++){
		if(content.at(i)==' '){
			words.push_back(word);
			word="";
			continue;
		}
		else if(i==content.size()-1){
			word+=content.at(i);
			words.push_back(word);
		}
		word+=content.at(i);
	}
	content="";
	vector<string>::iterator i=words.end()-1 ;
	for(i; i != words.begin(); --i ){
		content+=" "+(*i);
	}
}