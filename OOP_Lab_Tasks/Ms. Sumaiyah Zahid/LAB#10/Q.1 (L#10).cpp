#include<iostream>
#include<fstream>
using namespace std;
class Person{
	string Name;
	unsigned short Age;
	
	void Display()const{
		cout<<"\nName: "<<Name<<", Age: "<<Age<<endl;
    }
public:
	Person(string Name="No Name Provided!\a",unsigned short Age=0):Name(Name),Age(Age){}
	
	void Write_File_Data(){
		ofstream fout("Person.dat",ios::out|ios::binary);
        fout.write((char*)this,sizeof(Person));
        fout.close();
	}
	void Read_File_Data()const{
        ifstream fin("Person.dat",ios::in|ios::binary);
        if(!fin){
        	cout<<"File not present!";
        	return;
		}
		fin.read((char*)this,sizeof(Person));
        fin.close();
        Display();
    }
};
int main(){
	Person Person1("Shahzaib",21),Person2;
	Person1.Write_File_Data();
	Person2.Read_File_Data();
	return 0;
}
