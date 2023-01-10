#include<iostream>
using namespace std;


int func(int a, int b){
	return a*b;
}

int func(int a, int b, int c){
	return a*b*c;
}

float func(float a, float b){
	return a*b;
}

float func(float a, float b, float c){
	return a*b*c;
}

int main(){
	cout<<"First func: "<<func(5,6)<<endl;
	cout<<"Second func: "<<func(4,5,6)<<endl;
	cout<<"Third func: "<<func(2.6f,1.8f)<<endl;
	cout<<"Fourth func: "<<func(1.2f,3.4f,5.6f);
}
