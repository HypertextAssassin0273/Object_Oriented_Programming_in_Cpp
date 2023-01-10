#include<iostream>
using namespace std;

class student
{
	int id;
	string name;
	public:
		void getStudentdetails(int id, string name){
			this->id=id;
			this->name=name;
		}
		
		void display_stud(){
			cout<<"id: "<<id<<endl;
			cout<<"name: "<<name<<endl;
		}
};

class marks:public student
{
	protected:
		int marks_oop;
		int marks_pf;
		int marks_ds;
		int marks_db;
		
	public:
		void getMarks(int a, int b, int c, int d){
			marks_oop=a;
			marks_pf=b;
			marks_ds=c;
			marks_db=d;
		}
		
		void displayMarks(){
			cout<<"OOP MARKS: "<<marks_oop<<endl;
			cout<<"PF MARKS: "<<marks_pf<<endl;
			cout<<"DS MARKS: "<<marks_ds<<endl;
			cout<<"DB MARKS: "<<marks_db<<endl;
		}
};

class result:public marks
{
	protected:
		int total_marks;
		double avg_marks;
		
	public:
		void display(){
			cout<<"TOTAL MARKS: "<<total_marks;
			cout<<"AVERAGE MARKS: "<<avg_marks;
		}
		
		int totalmarks(){
			total_marks=marks_oop+marks_pf+marks_ds+marks_db;
		}
		
		int avgmarks(){
			avg_marks=(marks_oop+marks_pf+marks_ds+marks_db)/4;
		}
};



int main(){
	result ob1;
	
	cout<<"STUDENT DETAILS: "<<endl;
	ob1.getStudentdetails(143,"Rayyan");
	cout<<endl;
	ob1.display_stud();
	
	
	cout<<endl<<"MARKS: "<<endl;
	ob1.getMarks(56,76,13,45);
	cout<<endl;
	ob1.displayMarks();
	
	
	cout<<endl<<"TOTAL MARKS AND AVERAGE: "<<endl;
	ob1.totalmarks();
	ob1.avgmarks();
	
	ob1.display();
}
