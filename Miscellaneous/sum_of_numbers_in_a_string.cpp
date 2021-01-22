/*PROGRAM TO FIND SUM OF ALL NUMBERS PRESENT IN THE STRING*/
#include<bits/stdc++.h>
using namespace std;
// Function to find the sum of all  numbers present in the string
int calculate_sum(string str){
    string temp="";//i.e. intitialize temp
    int sum=0;//i.e. initialize sum
    for (char ch: str){//i.e. traverse the characters one by one
        if (isdigit(ch))//i.e. if the character is a digit
        temp+=ch;//i.e. add that character to temp
        else{
        sum+=atoi(temp.c_str());//i.e. add it with sum
        temp="";
        }
    }
    return sum+atoi(temp.c_str());//i.e. return the sum
}
int main(){
	cout<<"Enter a string which contains numbers: ";
    string str;
    cin>>str;//i.e. input the string from the user.
    cout<<calculate_sum(str);
    return 0;
}
