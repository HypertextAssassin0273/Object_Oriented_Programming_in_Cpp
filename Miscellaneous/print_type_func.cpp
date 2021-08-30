#include<iostream>

#if __cplusplus >= 201103L
template<typename... T>
#else
template<typename T>
#endif
void print_type(){ std::cout<<__PRETTY_FUNCTION__<<'\n'; }
//Note: it also doesn't discard cv-qualifiers

int main(){
	print_type<const char*>();
	return 0;
}
