#include<iostream>
using namespace std;

#if __cplusplus < 201103L
template<bool,typename=void> 
struct enable_if{};

template<typename T>
struct enable_if<true,T>{ typedef T type; };

template<typename T,typename _T>
struct is_same{
    static const bool value=false;
};
template<typename T>
struct is_same<T,T>{
    static const bool value=true;
};
#endif

/* DEDUCE CLASS (by type) */
template<typename T,typename=T>
struct remap{
	void func(){ cout<<"struct for generic types"; };
};

template<typename T>
struct remap<T,typename enable_if<    
									  is_same<T,char>::value
									||is_same<T,unsigned char>::value 
									||is_same<T,signed char>::value
									||is_same<T,int>::value
								,T>::type>{
    
	void func(){ cout<<"struct for specific types"; };
};

/* DEDUCE FUNCTION OVERLOADS (by argument type) */
template<typename T>
struct remap2{
		/* DEDUCE BY FUNC ARGUMENT TYPE (for func overloads) */
	void func2(typename enable_if<
									  is_same<T,char>::value
									||is_same<T,unsigned char>::value 
									||is_same<T,signed char>::value
									||is_same<T,int>::value
								,T>::type){ cout<<"func for specific types"; };
	template<typename Y>
	void func2(Y j){ cout<<"func for generic types"; };
};


int main(){
//	remap<string> obj;
	remap<int> obj;
	obj.func();
	cout<<endl;
	
	remap2<int> obj2;
//	obj2.func2("");
	obj2.func2(123);
    return 0;
}
