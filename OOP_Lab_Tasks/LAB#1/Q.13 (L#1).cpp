/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 13
*/
#include<iostream>
using namespace std;
int main(){
	int choice;
	cout<<"Input Month Number: ";
	cin>>choice;
	cout<<"Result: ";
	switch(choice){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
	    cout<<"Month has 31 days.\n";
	    break;
		case 2:
	    cout<<"February has 28 days normally. But, in leap year, it has 29 days.\n";
	    break;
		case 4:
		case 6:
		case 9:
		case 11:
	    cout<<"Month has 30 days.\n";
		break;
		default:
	    cout<<"invalid Month number.\n";
	    break;
      }
    return 0;
}

