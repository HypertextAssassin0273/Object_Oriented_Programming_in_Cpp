/*Recursive Variadic Function Template*/
#include<iostream>
using namespace std; 
namespace Print_Multiple_Args{
	void Print(){} //i.e. base case func for overloading 
	
	template<typename T,typename... Types> //i.e. typename = class 
	void Print(T Arg1,Types... Arg2){ //i.e. ... -> parameter pack: used for taking multiple args 
		cout<<Arg1;
		Print(Arg2...);
		/*Note: Func will recursively call variadic template based func until it recieves 
				zero args & then, it calls base func (using overloading concept) */
	}
}
template<typename T,typename... Types>
void display(void (*func)(T,Types...),T Arg1,Types... Arg2){// i.e. passing variadic func template as parameter (using func ptr)
	func(Arg1,Arg2...);
}
int main(){
   	display(Print_Multiple_Args::Print,"Brain usage: 100% xD!!\n",2.3,"\n",244);
   	/*Note: Only address of func will be passed, while if it's args are present, then they will be send seperately */
	return 0; 
} 

