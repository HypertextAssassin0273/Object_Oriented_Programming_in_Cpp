/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 4
*/
#include<iostream>
using namespace std;
void swap_floats(float *x,float *y){
	float *temp;
	*temp=*x;
	*x=*y;
	*y=*temp;
}
int main(){
float x=5.8,y=0.9;
swap_floats(&x,&y);
cout <<x<<" "<<y<<endl;
	return 0;
}

