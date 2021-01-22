#include<iostream>
#include<fstream>
using namespace std;
class Entry2{
    int original;
    string currency;

//	Entry2(string& in);
//	Entry2(string& original, string& currency):original(original), currency(currency){}
    
	friend ifstream& operator>>(ifstream& is,Entry2& en){
		is>>en.original;
    	is>>en.currency;
    	return is;
	}
	friend ofstream& operator<<(ofstream& os,const Entry2& en){
    	os<<en.original<<" "<<en.currency<<" ";
    	return os;
	}
	friend istream& operator>>(istream& is,Entry2& en){
		is>>en.original;
    	is>>en.currency;
    	return is;
	}
	friend ostream& operator<<(ostream& os,const Entry2& en){
    	os<<en.original<<" "<<en.currency<<" ";
    	return os;
	}
public:
	Entry2():original(1),currency("empty"){}
	Entry2(int original,string currency):original(original),currency(currency){}
    
	void read(string filename){
    	ifstream in(filename.c_str());
		in>>*this;
		//if you want to use read: 
		//in.read(reinterpret_cast<const char*>(&e),sizeof(e));
		in.close();	
	}
	void write(string filename){
		ofstream out(filename.c_str());
		out<<*this<<endl;
		out.close();
	}
};
int main(){
	Entry2 e,e1(322,"xxxz");
	e1.write("test.txt");
	e.read("test.txt");
	cout<<e;
	return 0;
}

