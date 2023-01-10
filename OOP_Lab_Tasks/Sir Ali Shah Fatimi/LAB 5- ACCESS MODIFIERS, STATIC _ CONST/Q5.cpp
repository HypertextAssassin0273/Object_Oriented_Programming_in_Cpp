#include<iostream>
using namespace std;

int main(){
	int x=45;
	const int a=10;
	//we can not increment this
	//a++ //not possible
	
	int b=15;
	const int *pB=&b;
	//we can not reallocate it with any other value but we can reassign
	pB=&x;
	//*pB=77; NOT POSSIBLE
	
	
	int c=27;
	int *const pC=&c;
	//we can reallocate but not reassign
	*pC=77;
	//pC=&a; NOT POSSIBLE

}
