#include<iostream>
using namespace std;
void hollow_rectangle(int length,int width,char symbol){
	for (int i=1;i<=length;i++){
		for (int j=1;j<=width;j++){
			if (i==1||i==length||j==1||j==width)
			cout<<symbol;
			else
			cout<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int length,width; char symbol;
	cout<<"Enter length & width of rectangle: ";
	cin>>length>>width;
	cout<<"Enter symbol for the frame: ";
	cin>>symbol;
	hollow_rectangle(length,width,symbol);
	system("pause");
	return 0;
}
