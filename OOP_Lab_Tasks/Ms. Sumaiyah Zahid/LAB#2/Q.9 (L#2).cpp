#include<iostream>
using namespace std;
int arr[]={0,1,2,3,4,5,6,7,8,9},size=sizeof(arr)/sizeof(arr[0]);
void reverse(int *arr){
	int temp[size];
	for(int i=0,j=size-1;i<size;i++,j--)
	temp[j]=arr[i];
	for(int i=0;i<size;i++)
	arr[i]=temp[i];
}
int main(){
	cout<<"Original Array: ";
	for(int i=0;i<size;i++)
	cout<<arr[i]<<" ";
	reverse(arr);
	cout<<"\nReverse Array: ";
	for(int i=0;i<size;i++)
	cout<<arr[i]<<" ";
	return 0;
}
