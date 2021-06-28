#include<iostream>
using namespace std;

#if __cplusplus < 201103L
template<typename _Tp,_Tp __v>
struct integral_constant{
    static const _Tp value=__v;
    typedef integral_constant<_Tp, __v> type;
};

typedef integral_constant<bool,true>  true_type;
typedef integral_constant<bool,false> false_type;

template<class T>
struct is_pointer_helper: false_type{};
template<class T>
struct is_pointer_helper<T*>: true_type{};

template<typename _Tp>
struct remove_volatile{ typedef _Tp type; };
template<typename _Tp>
struct remove_volatile<_Tp volatile>{ typedef _Tp type; };

template<typename _Tp>
struct remove_const{ typedef _Tp type; };
template<typename _Tp>
struct remove_const<_Tp const>{ typedef _Tp type; };

template<typename _Tp>
struct remove_cv{
    typedef typename remove_const<typename remove_volatile<_Tp>::type>::type type;
};

template<class T>
struct is_pointer: is_pointer_helper<typename remove_cv<T>::type>{};
#endif

struct A{};

int main(){	
    cout<<boolalpha
    	<<is_pointer<A>::value<<'\n'	
    	<<is_pointer<A*>::value<<'\n'	
    	<<is_pointer<A&>::value<<'\n'	
    	<<is_pointer<int>::value<<'\n'	
		<<is_pointer<int*>::value<<'\n'	
    	<<is_pointer<int**>::value<<'\n'	
    	<<is_pointer<int[10]>::value<<'\n';
    return 0;
}
