#include<iostream>
using namespace std;
void ascending_order(int *const ptr, int j){ //NOTE: const-> restricts the local ptr to be pointed towards another address inside this function
	if(ptr[j]>ptr[j+1]){
	int temp=ptr[j];
	ptr[j]=ptr[j+1];
	ptr[j+1]=temp;
	}
}
void descending_order(int *const ptr, int j){
	if(ptr[j]<ptr[j+1]){
	int temp=ptr[j];
	ptr[j]=ptr[j+1];
	ptr[j+1]=temp;
	}
}
void bubble_sort(int *const ptr,int size, void (*func)(int *const ptr, int j)){
	for(int i=0;i<size-1;i++)
		for(int j=0;j<size-1-i;j++)
			func(ptr,j);
}
int main(){
	int arr[]={23,-55,40,9,13,8,38,-4,1,66},size=sizeof(arr)/sizeof(arr[0]); //i.e. calculating allocated size of arr
	printf("UNSORTED ARRAY:-\n");
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	bubble_sort(arr,size,ascending_order); //i.e. using func ptr call
	printf("\n\nASCENDINGLY SORTED ARRAY:-\n");
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	bubble_sort(arr,size,descending_order);
	printf("\n\nDESCENDINGLY SORTED ARRAY:-\n");
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
}
