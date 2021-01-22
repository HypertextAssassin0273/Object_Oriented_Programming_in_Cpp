#include<iostream>
using namespace std;
#include<fstream>
namespace {
	inline bool Check_Files(){ return true; } //i.e. base case condition func
	
	template<typename T,typename... Types>
	bool Check_Files(T Arg1,Types... Args){
		fstream File(Arg1,ios::in);
		if(File){
			File.close();
			return Check_Files(Args...);
		}
		return false;
	}
}
int main(){
	if(!Check_Files("file1.txt","file2.txt")) //i.e. supply unlimited file name args
	cout<<"Error! All Files are not Found!\a";
	return 0;
}
