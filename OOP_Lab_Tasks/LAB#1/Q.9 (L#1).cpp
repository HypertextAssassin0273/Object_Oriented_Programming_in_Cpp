/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 9
*/
#include<iostream>
using namespace std;
int main(){
    int amount;
	cout<<"Enter the Amount: ";
    cin>>amount;
    int notes[6]={100,50,20,10,5,1},currency_count[6]={0};
    for (int i=0;i<6;i++){ //Note: Using Greedy approach for counting currency
        if (amount>=notes[i]){
            currency_count[i]=amount/notes[i];
            amount=amount-currency_count[i]*notes[i];
        }
    }
    cout<<"\nConverted Amount:-"<<endl;
    for (int i=0;i<6;i++){
        if (currency_count[i]!=0){
            cout<<notes[i]<<"'s: "<<currency_count[i]<<endl;
        }
    }
    return 0;
}
