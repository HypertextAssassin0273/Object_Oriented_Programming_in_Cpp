#include <iostream> 
using namespace std;
class Test{ 
public: 
	Test() { cout << "Constructor is executed\n"; } 
	~Test() { cout << "Destructor is executed\n"; } 
	friend void fun(Test t); 
}; 
void fun(Test t){ 
	Test(); 
	t.~Test(); 
} 
int main(){ 
	Test();
	Test t; 
	fun(t); 
	return 0; 
} 
/*NOTE: From output, it is observed that calling constructor or destructor basically allocates some memory.
  		Otherwise, there should be no further destructor calls made*/

