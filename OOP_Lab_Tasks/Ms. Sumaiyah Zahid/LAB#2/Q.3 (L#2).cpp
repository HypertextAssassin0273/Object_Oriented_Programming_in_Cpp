#include<iostream>
#include<cmath>
using namespace std;
void perfect_square(int initial,int final){
    for (int i=initial;i<=final;i++)
        if(sqrt(i)==trunc(sqrt(i))) //i.e. trunc(sqrt(i)) -> (int)sqrt(i)
        cout<<i<<" ";
}
int main(){
	int initial,final;
	cout<<"Enter range of perfect square series: ";
	cin>>initial>>final;
    perfect_square(initial,final);
	return 0;
}
