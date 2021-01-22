#include<iostream>
using namespace std;
template<class T1,class T2=T1> //i.e. now same data-types can be written as one
class Addition{
	T1 var1;
	T2 var2;
public:
	Addition(T1 var1,T2 var2):var1(var1),var2(var2){}
	void Display_Addition()const{ cout<<"Addition: "<<var1+var2<<endl; }
};
template<>
class Addition<char*>{
	string var1,var2;
public:
	Addition(string var1,string var2):var1(var1),var2(var2){}
	void Display_Addition()const{ cout<<"Addition: "<<var1+var2<<endl; }
};
int main(){
	Addition<int,double> obj(10,0.23);
	obj.Display_Addition();
	Addition<char*> obj2("Now","Then");
	obj2.Display_Addition();
	return 0;
}
