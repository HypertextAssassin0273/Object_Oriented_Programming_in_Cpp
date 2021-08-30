#include<iostream>
using namespace std;

template<typename T>
void print_type(){ std::cout<<__PRETTY_FUNCTION__<<'\n'; }//i.e. for debugging

template<typename type,size_t size>
struct array_adapter{
	type data[size];
};

/************* testing runtime parameter deduction for template-argument ****************/
/*NOTES: 
 	1) This technique basically allows us to use run-time parameters with compile-time
 	2) C++17 generic-lamba expression can also be used inside 'if' statement to make the function generic
*/
	template<size_t>
	void access_nth_tpp(size_t){}//i.e. base-case condition overload method
	
	template<size_t N,typename type,typename... types>
	void access_nth_tpp(const size_t& index){//i.e. tpp -> template parameter-pack
		if(index==N){//i.e. perform any operation inside if statement to make conversion 

			constexpr size_t Compile_Time_Coverted=N;//i.e. index == N , means any operation u want to do with 'index', can also be done with 'N'

			array_adapter<type,N*N> temp;//i.e. declares an array of N*N size perfectly, since both parameters are compile-time
//			array_adapter<type,index>();i.e. gives error, since its a run-time parameter

			print_type<type>();//i.e. access nth-type of parameter-pack at run-time with this method
			return;
		}
		access_nth_tpp<N+1,types...>(index);
	}
	
	template<typename... types>
	void Get_Access(size_t index){ access_nth_tpp<0,types...>(index); }

int main(){
	int index=2;
	Get_Access<int,char,std::string,bool>(index);//i.e. prints respective type
	return 0;
}
