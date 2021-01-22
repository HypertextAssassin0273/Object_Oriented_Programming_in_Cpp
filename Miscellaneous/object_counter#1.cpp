#include <iostream> 
using namespace std; 
class test { 
	int objNo; 
	static int objCnt;
	static bool warning_flag;
public:
	test(){
		objNo='\0';
		if (objCnt>=5){ //i.e. restricted for 5 objects only
		if(warning_flag){
		cout<<"Max. Limit for object creation has been attained!\n";
		warning_flag=0;
		}		
		return; //Alternate: this->test::~test();
		}
		objNo = ++objCnt; 
	} 
	~test(){
//		--objCnt; 
	} 
	void printObjNumber(){ 
		cout << "object number: " << objNo << "\n"; 
	} 
//	static void printObjCount(){ 
//		cout << "count:" << objCnt<< "\n"; 
//	} 
};
int test::objCnt=0; //vulnerability: anyone can modify the counter to bypass security rule i.e. 5-> -5
bool test::warning_flag=1;
int main(){
	int n=10;
	test t[n];
	for(int i=0;i<n;i++)
	
	t[i].printObjNumber();
//	test::printObjCount(); 
	return 0; 
}

