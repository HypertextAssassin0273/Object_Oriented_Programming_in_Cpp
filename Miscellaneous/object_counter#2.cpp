#include <iostream> 
using namespace std; 
class test{ 
	int objNo; 
	
	static int objCnt(short n, bool m) { //i.e. set to private for security
        static int x=0;
        static bool warning_flag=1;
        if(warning_flag&&m){
		cout<<"Max. Limit for object creation has been attained!\n";
		warning_flag=0;
		}
        if (n==1)
		return ++x;
		else if (!n)
		return --x;
		else
		return x;
    }
public:
	test(){
		objNo=objCnt(1,0);
		if (objNo>5){ //i.e. restricted for 5 objects only
		objNo=objCnt(0,1);	
		//return; //Alternate: this->test::~test();
		}
	} 
	void printObjNumber(){ 
		cout << "object number: " << objNo << "\n"; 
	} 
	static void printObjCount(){ 
		cout << "count:" << objCnt(-1,0)<< "\n"; 
	} 
	~test(){
		objCnt(0,0);
	}
};
int main(){
	int n=10;
	test t[n];
	for(int i=0;i<n;i++)
	t[i].printObjNumber();
	test::printObjCount(); 
	return 0; 
}

