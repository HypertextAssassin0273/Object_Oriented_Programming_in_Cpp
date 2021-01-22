#include <iostream> 
using namespace std;
class ABC {
protected: //i.e. this may be protected/public, no difference
    static int objCnt;
    int objNum;
	void woof(){
    	cout<<"woof "<<objNum<<endl;
	}
	ABC(){
		if (objCnt>=5)
		return;
		//this->ABC::~ABC();
		objNum=++objCnt;
	}
//public:

};
int ABC::objCnt;
class D: private ABC { // now woof is private
public:
//Note: using ABC::woof; -> 'using' declaration makes woof public, ABC::woof; -> but without 'using' it makes access declaration deprecated
	using ABC::woof;
	void printObjNumber(){ 
		cout << "objects created: " << objCnt << "\n"; 
	}
};
int main(){
	D x[10];
	x[10].woof();
	x[20].printObjNumber();
	return 0; 
}
