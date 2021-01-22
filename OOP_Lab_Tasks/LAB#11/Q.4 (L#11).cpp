#include<iostream>
using namespace std;
class Arr_Sum{
	Arr_Sum(){} //i.e. no obj can be created as no need
public:
	template<class T>
	static T Get_Arr_Sum(T arr[],unsigned int size){
		T sum=arr[0];
		for(unsigned int i=1;i<size;sum+=arr[i++]);
		return sum;
	}
	static string Get_Arr_Sum(const char* arr[],unsigned int size){//i.e. extra overloaded type for string alternative
		string sum=arr[0];
		for(unsigned int i=1;i<size;sum+=arr[i++]);
		return sum;
	}
};
int main(){
	int arr[] {1,2,3,4,5},size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Integer Array Sum: "<<Arr_Sum::Get_Arr_Sum(arr,size)<<endl;
	double arr2[] {1.1,2.2,3.3,4.4,5.5};
	size=sizeof(arr2)/sizeof(arr2[0]);
	cout<<"Double Array Sum: "<<Arr_Sum::Get_Arr_Sum(arr2,size)<<endl;
	const char* arr3[] {"Hi, ","my ","name ","is ","Shahzaib!"};
	size=sizeof(arr3)/sizeof(arr3[0]);
	cout<<"String Array Sum: "<<Arr_Sum::Get_Arr_Sum(arr3,size)<<endl;
	return 0;
}
