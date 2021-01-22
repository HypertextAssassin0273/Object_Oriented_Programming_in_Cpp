#include<iostream>
using namespace std;

class Base{ 
  public: 
	int base_int; 
 
	Base (int i){ 
		this -> base_int = i; 
    } 
 
    virtual int getInt(){ 
		return this -> base_int; 
	} 
}; 
 
class Derived : public Base{ 
  public: 
    int derived_int; 
 
    Derived (int i , int j) : Base(j){ 
	    	this -> derived_int = i; 
    }  
 
    int getInt(){ 
	    	return this -> derived_int; 
    } 
}; 
 
int main() { 
	Base* basePointerToBase = new Base(0); 
	Base* basePointerToDerived = new Derived(10, 5); 
	cout << basePointerToBase->getInt() << endl; 
	cout << basePointerToDerived->getInt(); 
//	cout << basePointerToBase->derived_int;
	cout << basePointerToDerived->derived_int;
	return 0; 
}
