#include <iostream>
using namespace std;
int main(){
   	float numerator,denominator;
   	while(true){//i.e. handling divide by zero
   		cin.clear();
   		cin.sync();
   		cout <<"Enter 1st num: ";
		cin >> numerator;
		cout <<"Enter 2nd num: ";
		cin >> denominator;
  		try {
  	    	if (!numerator||!denominator)
     			throw;
  	    	cout << "The quotient is: " << numerator/denominator << endl;
   	   		break;
	   	}
	   	catch(...){
	    	cout << "\nException occurred" << endl;
	    }
	}
}
