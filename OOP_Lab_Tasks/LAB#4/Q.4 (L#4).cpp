#include<iostream>
using namespace std;
class student{
	string name,roll_no;
	int semester;
	char section;
public:
	student(string name,string roll_no,int semester,char section){
		this->name=name,this->roll_no=roll_no;
		this->semester=semester;
		this->section=section;
	}
	void display_data(){
		cout<<"Name: "<<name<<endl
			<<"Roll No: "<<roll_no<<endl
			<<"Semester: "<<semester<<endl
			<<"Section: "<<section<<endl;
	}
};
int main(){
	student s1("Shahzaib Khan","19K-0273",3,'C');
	s1.display_data();
	return 0;
}
