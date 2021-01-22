/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 6
*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void digit_name(int x){
	cout<<"Result: ";
	switch(x){
		case 1:    
		cout<<"one";    
		break;    
		case 2:    
		cout<<"two";    
		break;    
		case 3:    
		cout<<"three";  
		break;    
		case 4:    
		cout<<"four";  
		break;    
		case 5:    
		cout<<"five";  
		break;    
		case 6:    
		cout<<"six";   
		break;    
		case 7:  
		cout<<"seven";  
		break;  
		case 8:    
		cout<<"eight";    
		break;    
		case 9:    
		cout<<"nine";  
		break;        
		default:    
		cout<<"digit error"<<endl;    
		break;    
	}
}
int main(){
	cout<<"Enter any single digit: ";
	digit_name(getchar()-48);
	getch();
	return 0;
}
