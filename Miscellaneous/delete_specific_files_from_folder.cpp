#include<iostream>
using namespace std;
int main(){
	string command="del /Q ",path="\"path\\*.txt\"";
	system(command.append(path).c_str());
	return 0;
}
