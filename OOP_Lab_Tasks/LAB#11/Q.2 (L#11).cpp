#include<iostream>
using namespace std;
template<class T>
void Bubble_Sort(T arr[],int size){
	for (unsigned short i=0;i<size-1;++i){
    	bool swapped=false;
     	for (unsigned short j=0;j<size-1-i;++j){
        	if (arr[j]>arr[j+1]){
           		T temp=arr[j];
           		arr[j]=arr[j+1];
           		arr[j+1]=temp;
				swapped=true;
    		}
     	}
     	if (!swapped)//i.e. break if no elements were swapped
        	break;
   }
}
template<class T>
void Display_Arr(T arr[],int size){
	for (unsigned short i=0;i<size;++i) 
		cout<<arr[i]<<", ";
}
int main(){
	int arr[] {7,5,4,3,9,8,6},size=sizeof(arr)/sizeof(arr[0]);//Note: (no. of elements in arr)=(total arr size)/(arr data-type)
	Bubble_Sort(arr,size);
	cout<<"Sorted Integer Array: \n";
	Display_Arr(arr,size);
	float arr2[] {4.3,2.5,-0.9,100.2,3.0};
	size=sizeof(arr2)/sizeof(arr2[0]);
	Bubble_Sort(arr2,size);
	cout<<"\nSorted Float Array: \n";
	Display_Arr(arr2,size);
	return 0;
}
