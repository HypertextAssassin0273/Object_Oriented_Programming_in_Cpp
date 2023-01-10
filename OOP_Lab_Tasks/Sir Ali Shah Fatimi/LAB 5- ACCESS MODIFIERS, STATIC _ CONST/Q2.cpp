#include<iostream>
using namespace std;

class Student{
	int scores[5];
	
	public:
		void input(){
			int i;
			for(i=0;i<5;i++){
				cout<<"Enter score of "<<i+1<<" exam: ";
				cin>>scores[i];
			}
			
		}
		
		int calculateTotalScore(){
			int i,sum=0;
			for(i=0;i<5;i++){
				sum=sum+scores[i];
			}
			cout<<"Total sum of marks are: "<<sum;
		}
};

int main(){
	
	Student ob1;
	ob1.input();
	ob1.calculateTotalScore();
	
}
