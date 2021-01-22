#include<iostream>
using namespace std;
class TC_Machine{
public:
	virtual void Add_Sachets()const=0;
	
	void Hot_Water()const{ cout<<"	Add Hot Water"<<endl; }
	void Milk()const{ cout<<"	Add Milk"<<endl; }
	void Sugar()const{ cout<<"	Add Sugar"<<endl; }
};
class Tea: public TC_Machine{
public:
	Tea(){ cout<<"Preparing Tea..."<<endl; }
	void Add_Sachets()const override{ cout<<"	Add Tea"<<endl; }
};
class Coffee: public TC_Machine{
public:
	Coffee(){ cout<<"Preparing Coffee..."<<endl; }
	void Add_Sachets()const override{ cout<<"	Add Coffee"<<endl; }
};
int main(){
	TC_Machine *obj_ptr;
	obj_ptr=new Tea;
	obj_ptr->Hot_Water();
	obj_ptr->Milk();
	obj_ptr->Sugar();
	obj_ptr->Add_Sachets();
	delete obj_ptr;
	obj_ptr=new Coffee;
	obj_ptr->Hot_Water();
	obj_ptr->Milk();
	obj_ptr->Sugar();
	obj_ptr->Add_Sachets();
	return 0;  
}

