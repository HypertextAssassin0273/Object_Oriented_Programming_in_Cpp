//exercise#4
#include<iostream>
using namespace std;
class Marks{
public:
	virtual float Get_Percentage()const=0;
};
class Student_A:public Marks{
	float Subject_Marks[3];
public:
	Student_A(float Marks1=0,float Marks2=0,float Marks3=0):Subject_Marks{Marks1,Marks2,Marks3}{}
	float Get_Percentage()const override{ return ((Subject_Marks[0]+Subject_Marks[1]+Subject_Marks[2])/300)*100; }
};
class Student_B:public Marks{
	float Subject_Marks[4];
public:
	Student_B(float Marks1=0,float Marks2=0,float Marks3=0,float Marks4=0):Subject_Marks{Marks1,Marks2,Marks3,Marks4}{}
	float Get_Percentage()const override{ return ((Subject_Marks[0]+Subject_Marks[1]+Subject_Marks[2]+Subject_Marks[3])/400)*100; }
};
int main(){
	Student_A obj1(33,44,55.5);
	cout<<"Student A Percentage: "<<obj1.Get_Percentage()<<endl;
	Student_B obj2(50,50,30,70);
	cout<<"Student B Percentage: "<<obj2.Get_Percentage()<<endl;
	return 0;
}
