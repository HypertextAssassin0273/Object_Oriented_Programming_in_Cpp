#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Inventory{
	char Description[20];
	unsigned int Item_Code,Total_Units;
	float Rate_per_Unit;

	void Display(unsigned short Item_Index)const{
		cout<<"Item "<<Item_Index<<":-\n"
			<<"Description: "<<Description<<endl
			<<"Item Code: "<<Item_Code<<endl
			<<"Total Units in Stock: "<<Total_Units<<endl
			<<"Rate per Unit: "<<Rate_per_Unit<<"\n\n";
	}
public:
	Inventory(const char* Description="N.i.l",unsigned int Item_Code=0,unsigned int Total_Units=0,float Rate_per_Unit=0):
		Item_Code(Item_Code),Total_Units(Total_Units),Rate_per_Unit(Rate_per_Unit){ strcpy(this->Description,Description); }
	
	void Update_Stock(unsigned short Item_Index){
		ofstream fout("Inventory.dat",ios::in|ios::ate|ios::binary);
		if(!fout){
			cout<<"File not Found!"<<"\n\n";
			return;
		}
		cout<<"Enter Total Units in Stock: ";
		cin>>Total_Units;
        fout.seekp((Item_Index-1)*sizeof(*this),ios::beg);
		fout.write((char*)this,sizeof(*this));
        fout.close();
	}
	static void Display_Details(unsigned int Code){
		Inventory obj;
        ifstream fin("Inventory.dat",ios::in|ios::binary);
        if(!fin){
			cout<<"File not Found!"<<"\n\n";
			return;
		}
		for(unsigned short i=0;fin.read((char*)&obj,sizeof(obj));++i){
			if (Code==obj.Item_Code){
		    	obj.Display(i+1);
				fin.close();
				return;
			}
		}
		cout<<"Item not Found!"<<"\n\n";
        fin.close();
	}
	static void Display_Details(){
		Inventory obj;
		ifstream fin("Inventory.dat",ios::in|ios::binary);
		if(!fin){
			cout<<"File not Found!"<<"\n\n";
			return;
		}
		for(unsigned short i=0;fin.read((char*)&obj,sizeof(obj));)
			obj.Display(++i);
        fin.close();
	}
};
int main(){
	Inventory obj[5]={Inventory("Blue-Band Butter",10101,1000,150), //i.e ctor's returns *this ptr
					  Inventory("Brady's Bread",20202,500,60),
					  Inventory("Desi Eggs",30303,450,99.9),
					  Inventory("Bisconni Biscuits",40404,32,50),
					  Inventory("Chips",50505,1200,20)};
	ofstream fout("Inventory.dat",ios::out|ios::binary);
    for(unsigned short i=0;i<5;++i)
		fout.write((char*)&obj[i],sizeof(obj[i]));
    fout.close();
    unsigned int choice;
	while(true){
		cout<<"Main-Menu:-\n^^^^^^^^^^^\n1) Update Specific Item Stock\n2) Display Specific Item Details\n3) Display all Items Details\n4) Exit\n==> ";
		cin>>choice;
		cin.clear();
		cin.sync();
		system("cls");
		switch(choice){
    		case 1:
    			cout<<"Enter Item Index: ";
				cin>>choice;
				obj[choice-1].Update_Stock(choice); //i.e. updates both file-data & within program-data
    			break;
    		case 2:
    			cout<<"Enter Item Code: ";
				cin>>choice;
    			Inventory::Display_Details(choice);
    			break;
    		case 3:
    			Inventory::Display_Details();
    			break;
    		case 4:
    			return 0;
		}
	}
	return 0;
}
