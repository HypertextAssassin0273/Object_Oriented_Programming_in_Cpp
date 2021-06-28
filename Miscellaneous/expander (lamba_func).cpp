#include<iostream>
using namespace std;

template<typename ...Args>
void Write(Args&&... args){
	int expander[]={ (cout << ", " << std::forward<Args>(args), 0)... };
    
    cout<<endl<<sizeof(expander)/sizeof(expander[0])<<endl;
	//for(int i=0;i<6;++i)
    	if(cout<<expander[0]<<" ")
    		cout<<endl;
}

int main(){
    Write(1, "Hello", 2, "World", 3, 1.4857);
    return 0;
}
