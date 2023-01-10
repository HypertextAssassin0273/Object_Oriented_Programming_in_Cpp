#include<iostream>
using namespace std;
class items{
	unsigned int code_no;
	float price;
	
	items(){
		code_no=0; price=0;
	}
	void input_data(){
		cout<<"	Enter Code No: ";
		cin>>code_no;
		cout<<"	Enter Price: ";
		cin>>price;
	}

	friend class shopping_list;
};
class shopping_list{
	unsigned char quantity,size; //i.e. range: 0-255
	float total;
	items **item;

	shopping_list(){
		size=10;
		item=new items*[size]; //i.e. range of items: 0>N>256
		quantity=0, total=0;
	}
	void resize_items(){
		if (quantity>=size){
		cout<<"\nNote: Items array has been increased from "<<(short)size<<" to "<<(short)size+10<<"\n\n\a";
		items** new_item=new items*[size+10];
  		memcpy(new_item,item,size*sizeof(items*));
    	size+=10;
    	delete []item;
    	item=new_item;
		}
		else if (quantity<size-10){
		cout<<"\nNote: Items array has been decreased from "<<(short)size<<" to "<<(short)size-10<<"\n\n\a";
		items** new_item=new items*[size-10];
  		for (unsigned char i=0;i<quantity;i++)
  		new_item[i]=item[i];
    	size-=10;
    	delete []item;
    	item=new_item;
		}	
	}
	void add_item(){
		item[quantity++]=new items;
		cout<<"Item "<<(short)quantity<<":-"<<endl;
		item[quantity-1]->input_data();
		total+=item[quantity-1]->price;
	}
	void delete_last_item(){
		if (quantity>0){
		total-=item[--quantity]->price;
		delete item[quantity];
		}
		else
		cout<<"\nWarning: No item is present!\a";
	}
	void display_data(){
		cout<<"\nShopping List:-"<<endl
			<<"	Quantity of Items: "<<(short)quantity<<endl
			<<"	Items:"<<endl;
		for (unsigned char i=0;i<quantity;i++)
		cout<<"		item "<<i+1<<") code no: "<<item[i]->code_no<<", price: "<<item[i]->price<<endl;
		cout<<"	Total Price of Order: "<<total;
	}
	~shopping_list(){
		for (unsigned char i=0;i<quantity;i++)
		delete item[i];
		delete item;
	}
	
	friend class departmental_store;
};
class departmental_store{ //Find: Is this class & interfaces in C# are somehow same or related?
	departmental_store(){} //i.e. making private constructor, so that no object can be created
public:
	static void main_menu(){
		unsigned short list_no,N;
		while(1){
			cout<<"Enter Number of shopping lists u want: ";
			cin>>N;
			if (N>0)
			break;
			cout<<"\aRe-";	
		}
		shopping_list list[N];
	change_list:
		cout<<endl;
		while(1){
			cout<<"Enter shopping list number (1-"<<N<<"): ";
			cin>>list_no;
			if (list_no>0&&list_no<=N)
			break;
			cout<<"\aRe-";	
		}
		while(1){
			unsigned short choice;
			cout<<"\nMAIN-MENU"<<endl
				<<"1) Add Item"<<endl
				<<"2) Delete Last Item"<<endl
				<<"3) View Shopping List"<<endl
				<<"4) Clear Screen"<<endl
				<<"5) Change Shopping List Number"<<endl
				<<"6) Exit"<<endl
				<<"==> ";
			cin>>choice;
			switch (choice){
				case 1:
				list[list_no-1].add_item();	
				break;
				case 2:
				list[list_no-1].delete_last_item();	
				break;
				case 3:
				list[list_no-1].display_data();	
				break;
				case 4:
				system("cls");	
				break;
				case 5:
				goto change_list;
				case 6:
				return;	
				break;
				default:
				break;
			}
			list[list_no-1].resize_items();
			cout<<"\n";
		}	
	}
};
int main(){
	departmental_store::main_menu();
	return 0;
}
/*
NOTE: Find alternate for dynamic allocation of objects
	  in order to avoid vector approach. (Done)
*/
