#include<iostream>
using namespace std;

class B{
protected:
	 int v;
public:
	B(int v=0):v(v){}
	B& operator=(const B& other){
    	v=other.v;
    	return *this;
  	}
  	friend ostream& operator<<(ostream& out,const B& obj){
  		cout<<obj.v<<endl;
		return out;	
	}
};

class D:public B{
	int w;
public:
	D(int v=0,int w=0):B(v),w(w){}
	D& operator=(const D& other){
		w=other.w;
    	B::operator=(other);//i.e. object slices/deduces into constB& type
    	return *this;
  	}
  	friend ostream& operator<<(ostream& out,const D& obj){
  		cout<<obj.v<<", "<<obj.w<<endl;
		return out;	
	}
};

int main(){
	D obj,obj2(1),obj3(1,1);
	cout<<"Before:-\nobj: "<<obj<<"obj2: "<<obj2<<"obj3: "<<obj3;
	obj=obj3;
	cout<<"After:-\nobj: "<<obj<<"obj2: "<<obj2<<"obj3: "<<obj3;
	return 0;
}

