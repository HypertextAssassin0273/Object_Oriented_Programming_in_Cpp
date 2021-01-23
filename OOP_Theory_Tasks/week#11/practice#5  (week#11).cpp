//exercise#5
#include<iostream>
using namespace std;
template<class T>
class Items_Set{
	unsigned int Items_Counter;
	T Items[100];
public:
	Items_Set():Items_Counter(0){}
	void Add_New_Item(T Item){// part a
		for(unsigned int i=0;i<Items_Counter;++i)
			if(Items[i]==Item)
				return;
		Items[Items_Counter++]=Item;
	}
	void Remove_Item(T Item){// part b
		for(unsigned int i=0;i<Items_Counter;++i)
			if(Items[i]==Item){
				--Items_Counter;
				for(unsigned int j=i;j<Items_Counter;++j)
					Items[j]=Items[j+1];
				return;
			}
		cout<<"'"<<Item<<"' isn't present in the set!"<<endl;
	}
	int Get_Total_Items()const{ return Items_Counter; }// part c
	void Check_Item(T Item){// part d
		for(unsigned int i=0;i<Items_Counter;++i)
			if(Items[i]==Item){
				cout<<"'"<<Item<<"' is member of the set!"<<endl;
				return;
			}
		cout<<"'"<<Item<<"' isn't member of the set!"<<endl;
	}
	void Display_Set_Items()const{// extra
		cout<<"Set Members: ";
		for(unsigned int i=0;i<Items_Counter;cout<<Items[i++]<<", ");
		cout<<"\b\b "<<endl;
	}
};
int main(){
	{//i.e. defined local scope to destroy obj
		Items_Set <string>obj;
		obj.Add_New_Item("hi");
		obj.Add_New_Item("bye");
		obj.Add_New_Item("bye");
		obj.Add_New_Item("no-no");
		obj.Display_Set_Items();
		cout<<"No of Items: "<<obj.Get_Total_Items()<<endl;
		obj.Check_Item("no-no");
		obj.Remove_Item("bye");
		obj.Display_Set_Items();
		cout<<endl;
	}
	{
		Items_Set <int>obj;
		obj.Add_New_Item(99);
		obj.Add_New_Item(44);
		obj.Add_New_Item(101);
		obj.Add_New_Item(44);
		obj.Display_Set_Items();
		cout<<"No of Items: "<<obj.Get_Total_Items()<<endl;
		obj.Check_Item(101);
		obj.Remove_Item(44);
		obj.Remove_Item(111);
		obj.Display_Set_Items();
		cout<<endl;	
	}
	{
		Items_Set <char>obj;
		obj.Add_New_Item('x');
		obj.Add_New_Item('3');
		obj.Add_New_Item('@');
		obj.Add_New_Item('*');
		obj.Display_Set_Items();
		cout<<"No of Items: "<<obj.Get_Total_Items()<<endl;
		obj.Check_Item('3');
		obj.Remove_Item('x');
		obj.Remove_Item('@');
		obj.Remove_Item('x');
		obj.Check_Item('@');
		obj.Display_Set_Items();	
	}
	return 0;
}
