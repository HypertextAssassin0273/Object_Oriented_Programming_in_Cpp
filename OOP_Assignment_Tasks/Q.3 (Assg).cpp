#include<iostream>
using namespace std;
class Quad{
protected:
	float l1,l2,l3,l4;
public:	
	virtual float Area()const=0;
	
	void Set_Side_Lengths(float l1=1,float l2=1,float l3=1,float l4=1){
	//Note: Initialized by 1, so the product of side_lengths shouldn't be affected 
		this->l1=l1;
		this->l2=l2;
		this->l3=l3;
		this->l4=l4;
	}
	float _Area(const Quad& obj)const{ //i.e. it can accept any derived obj
		return obj.l1*obj.l2*obj.l3*obj.l4;
	}
};
class Rectangle: public Quad{
public:
	float Area()const override{
		return l1*l2;
	}
};
int main(){
	Rectangle obj1,obj2,obj3;
	obj1.Set_Side_Lengths(5,5);
	obj2.Set_Side_Lengths(3,3,3);
	obj3.Set_Side_Lengths(1,2,3,4);
	cout<<"Area of Obj1: "<<obj1.Area()<<endl;
	cout<<"Area of Obj2: "<<obj1._Area(obj2)<<endl;
	cout<<"Area of Obj3: "<<obj3._Area(obj3)<<endl;
	return 0;  
}

