#include<iostream>
using namespace std;
class Prime_Number{
	unsigned int Prime_No;
	static unsigned short Prime_No_Limit;

	static unsigned int Find_Prime_by_Index(unsigned short Index,bool increment_or_decrement_Flag){
		static bool X=1;
		static unsigned int *Prime_Arr=new unsigned int[Prime_No_Limit];
		if (X){
		for (unsigned __int64 count=0,i=2;count<Prime_No_Limit;++i){ //i.e. skipping 0 & 1 as they aren't primes
			bool Flag=1;
			for (unsigned int j=2;j<=i/2;++j){
				if (!(i%j)){
				Flag=0;
				break;
				}
			}
			if (Flag)
			Prime_Arr[count++]=i; //i.e. storing 'N' prime Numbers
		}
		X=0;
		}
		for (unsigned short i=0;i<Prime_No_Limit;i++){
			if (Prime_Arr[i]==Index){
				if (increment_or_decrement_Flag)
				return Prime_Arr[++i];
				else
				return Prime_Arr[--i];
			}
		}
		return 0; //i.e. if not present in prime arr
	}
public:
	Prime_Number():Prime_No(2){} //i.e. default to 1st prime
	Prime_Number(unsigned int Prime_No):Prime_No(Prime_No){}
	
	unsigned int Get_Prime_No()const{ return Prime_No; }
	void Set_Prime_No(unsigned int Prime_No){ this->Prime_No=Prime_No; }
	
	Prime_Number operator++(){ //i.e. pre-increment
         Prime_No=Find_Prime_by_Index(Prime_No,1);
         return *this;
      }
	Prime_Number operator++(int){ //i.e. post-increment
		Prime_Number temp;
         temp=Prime_No;
         Prime_No=Find_Prime_by_Index(Prime_No,1);
         return temp;
      }
	Prime_Number operator--(){ //i.e. pre-decrement
         Prime_No=Find_Prime_by_Index(Prime_No,0);
         return *this;
      }
	Prime_Number operator--(int){ //i.e. post-decrement
		Prime_Number temp;
         temp=Prime_No;
         Prime_No=Find_Prime_by_Index(Prime_No,0);
         return temp;
      }
};
unsigned short Prime_Number::Prime_No_Limit=21; //Limit: 2-65355 (i.e. increase upto your requirment)
int main(){
	Prime_Number obj1(11),obj2(17);
	cout<<"Initial values:-\n";
	cout<<"Obj 1: "<<obj1.Get_Prime_No()<<endl;
	cout<<"Obj 2: "<<obj2.Get_Prime_No()<<"\n\n";

	obj2=++obj1;		
	cout<<"Pre-increment of Obj1 & assigning Obj1 to Obj2:-\n";
	cout<<"Obj 1: "<<obj1.Get_Prime_No()<<endl;
	cout<<"Obj 2: "<<obj2.Get_Prime_No()<<"\n\n";
	
	obj1.Set_Prime_No(11);
	obj2.Set_Prime_No(17);
	obj2=obj1++;		
	cout<<"Post-increment of Obj1 & assigning Obj1 to Obj2:-\n";
	cout<<"Obj 1: "<<obj1.Get_Prime_No()<<endl;
	cout<<"Obj 2: "<<obj2.Get_Prime_No()<<"\n\n";
	
	obj1.Set_Prime_No(11);
	obj2.Set_Prime_No(17);
	obj2=--obj1;		
	cout<<"Pre-decrement of Obj1 & assigning Obj1 to Obj2:-\n";
	cout<<"Obj 1: "<<obj1.Get_Prime_No()<<endl;
	cout<<"Obj 2: "<<obj2.Get_Prime_No()<<"\n\n";
	
	obj1.Set_Prime_No(11);
	obj2.Set_Prime_No(17);
	obj2=obj1--;		
	cout<<"Post-decrement of Obj1 & assigning Obj1 to Obj2:-\n";
	cout<<"Obj 1: "<<obj1.Get_Prime_No()<<endl;
	cout<<"Obj 2: "<<obj2.Get_Prime_No()<<"\n\n";
	
	cout<<"Utilizing all available operators in loop:-\n"
		<<"Pre-increment: Post-increment: Pre-decrement: Post-decrement:\n";
	for (Prime_Number w,x,y=73,z=73;w.Get_Prime_No()<=71;++w,x++,--y,z--) //i.e. prints first 20 primes
		cout<<w.Get_Prime_No()<<"\t\t"
			<<x.Get_Prime_No()<<"\t\t"
			<<y.Get_Prime_No()<<"\t\t"
			<<z.Get_Prime_No()<<endl;
	
	return 0;
}
