#include<iostream>
using namespace std;
class String_with_Marker{
	string str;
	string::iterator marker;
public:
	String_with_Marker(string s="N.I.L",unsigned __int64 index=0):str(s),marker(str.begin()+index){}
	String_with_Marker(const String_with_Marker& s):str(s.str),marker(s.marker-'0'){}
	String_with_Marker& operator=(const String_with_Marker& s){
		str=s.str;
		marker=s.marker-'0';
 		return *this;
 	}
 	void Set_Str(string s){ str=s, marker=s.begin(); }
 	void Set_Marker(unsigned __int64 index){ marker=str.begin()+index; }
	string Get_Str()const{ return str; }
	const string::iterator Get_Marker()const{ return marker; }
};
int main(){
	String_with_Marker obj1("shah-zaib",4),obj2=obj1;
	obj1.Set_Str("awesome, nice");
	obj1.Set_Marker(7);
	cout<<"obj1:-\n"<<obj1.Get_Str()<<endl;
	cout<<*obj1.Get_Marker()<<endl;
	cout<<"obj2:-\n"<<obj2.Get_Str()<<endl;
	cout<<*obj2.Get_Marker();
	return 0;
}
