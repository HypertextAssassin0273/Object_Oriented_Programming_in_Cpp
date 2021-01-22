/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 12
*/
#include<iostream>
#include<string.h>
using namespace std;
void digit_to_word_convertor(char *num){
    const char *single_digits[]={"zero","one","two","three","four","five","six","seven","eight","nine"},
    		   *two_digits[]={"","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"},
    		   *tens_multiple[]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"},
			   *tens_power[]={"hundred","thousand"};
	int len=strlen(num);
    /*Single number*/
    if (len==1){
    cout<<single_digits[*num-'0']; //i.e. '0'->48
	return;
    }
    while (*num!='\0'){
        if (len>=3){
        if (*num-'0'!=0) {
        cout<<single_digits[*num-'0']<<" ";
        cout<<tens_power[len-3]<<" "; //i.e. here len can be 3 or 4
        }
        --len;
        }
        /*For last 2 digits*/
        else{
        if (*num=='1'){
        int sum=*num-'0'+*(num+1)-'0';
        cout<<two_digits[sum]<<" ";
        return;
        }
        else if(*num=='2'&&*(num+1)=='0'){
        cout<<"twenty\n";
        return;
        }
        /*Number range: 21 to 99*/
        else{
        int i=*num-'0';
        cout<<(i?tens_multiple[i]:"")<<" ";
        ++num;
        if (*num!='0')
        cout<<single_digits[*num-'0']<<" ";
        }
        }
        ++num;
    }
}
int main(){
    char a[10];
    cout<<"Input: ";
    cin>>a;
    cout<<"\nOutput: ";
    digit_to_word_convertor(a);
    return 0;
}

