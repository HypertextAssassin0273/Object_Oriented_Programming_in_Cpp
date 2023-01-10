#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
	fstream fp;
	fp.open("STORY.txt",ios::in);
	
	string x;
	int count=0;

	char arr[25];

	while(!fp.eof()){
		getline(fp,x);
		arr[0]=x[0];
		
		if(arr[0]!='A'){
			count++;
		}
	}
	
	cout<<count;
	
	
}
