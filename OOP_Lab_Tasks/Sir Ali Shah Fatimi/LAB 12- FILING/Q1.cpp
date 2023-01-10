#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
	//Q1 WRITING STRING INTO FILE
//	fstream fp;
//	fp.open("hello.txt",ios::app);
//	
	string txt;
	char ch;
	int len=0;
//	
//	cout<<"Input string u want to write in file: ";
//	cin>>txt;
//	fp.close();
	
	
	
	//Q1 READING CHARS FROM FILE
	fstream f;
	f.open("hello.txt",ios::in);
	
	f << txt;
	
	cout<<"String in file is: ";
	while(!f.eof()){
		f.get(ch);
		len++;
		if(!f.eof())
		cout<<ch;
		
		
	}
	
	cout<<endl<<"length of inputted string: "<<len-1;
}
