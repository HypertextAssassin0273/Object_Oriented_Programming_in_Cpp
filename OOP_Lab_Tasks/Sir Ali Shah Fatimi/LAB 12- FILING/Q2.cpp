#include<iostream>
#include<string>
#include<fstream>

using namespace std;


int main(){
	fstream fp;
	fstream f;
	
	fp.open("hello.txt",ios::in);
	f.open("new.txt",ios::out);
	
	char ch;
	
	while(!fp.eof()){
		fp.get(ch);
		if(!fp.eof())
		f.put(ch);
	}
	
	cout<<"contents have been copied into new file";
}
