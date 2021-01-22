#include <iostream> 
using namespace std; 

// A class whose object can only be dynamically created 
class Test 
{ 
private: 
	~Test() { cout << "Destroying Object\n"; } 
public: 
	Test() { cout << "Object Created\n"; } 
friend void destructTest(Test* ); 
}; 

// Only this function can destruct objects of Test 
void destructTest(Test* ptr) 
{ 
	delete ptr; 
	cout << "Object Destroyed\n"; 
} 

int main() 
{ 
	/* Uncommenting following following line would cause compiler error */
	// Test t1; 

	// create an object 
	Test *ptr = new Test; 

	// destruct the object to avoid memory leak 
	destructTest(ptr); 

	return 0; 
} 

