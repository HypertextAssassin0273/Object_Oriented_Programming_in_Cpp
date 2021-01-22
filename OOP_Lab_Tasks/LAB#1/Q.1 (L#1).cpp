/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 1
*/
#include<iostream>
using namespace std;
int main(){
	int x=98,flag=1,count=0;
	while(1){
		if (flag){
		cout<<(x+=2)<<endl;
		flag=0;
		if (count>3)
		break;
		}
		else{
		cout<<(x/=2)<<endl;
		flag=1;
		}
		count++;
	}
	return 0;
}
