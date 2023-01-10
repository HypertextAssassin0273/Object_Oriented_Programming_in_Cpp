#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Person{
	char name[15];
	int age;
	
	public:
		Person(){
			
		}
	
		
		Person(char *n, int a){
			int i=0;
			
			while (n[i]!='\0'){
				name[i]=n[i];
				i++;
			}
			
			age=a;
			
		}
		
		void display(){
			cout<<name;
			cout<<"age: "<<age;
		}
		
		
		
		
		
};

int main(){
	char name[15]="Rayyan";
	Person ob1(name,18);
	Person ob2;
	fstream fp;
	fp.open("question3",ios::out | ios::binary);
	
	fp.write((char *)&ob1,sizeof(ob1));
	fp.close();

	fstream f;
	f.open("question3",ios::in | ios::binary);
	
	f.write((char *)&ob2,sizeof(ob2));
	
	return 0;
	
}
