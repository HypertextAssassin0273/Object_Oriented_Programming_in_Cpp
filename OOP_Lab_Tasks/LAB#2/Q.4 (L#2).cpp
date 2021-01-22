#include<iostream>
using namespace std;
int is_Prime(int num){
    for(int i=2;i<=num/2;i++){
        if(!(num%i))
        return 0;
    }
    return 1;
}
void print_Primes(int lower_Limit,int upper_Limit){
    cout<<"All prime number b/w "<<lower_Limit<<" to "<<upper_Limit<<" are: ";
    while(lower_Limit<=upper_Limit){
        if(is_Prime(lower_Limit))
        cout<<lower_Limit<<" ";
        lower_Limit++;
    }
}
int main(){
    int lower_Limit,upper_Limit;
    cout<<"Enter the range for prime number series: ";
    cin>>lower_Limit>>upper_Limit;
    print_Primes(lower_Limit,upper_Limit);
    return 0;
}
