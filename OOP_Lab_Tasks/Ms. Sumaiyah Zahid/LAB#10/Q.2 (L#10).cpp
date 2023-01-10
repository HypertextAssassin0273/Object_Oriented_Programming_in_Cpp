#include<iostream>
using namespace std;
#include<fstream>
class Participant{
	char Name[20];
	unsigned int ID,Score;
		
	void Input(){
		cout<<"Enter ID: ";
		cin>>ID;
		cout<<"Enter Name: ";
		cin>>Name;
		cout<<"Enter Score: ";
		cin>>Score;
	}
	void Display()const{
		cout<<"\nID: "<<ID<<", Name: "<<Name<<", Score: "<<Score<<endl;
    }
public:
	Participant():Name{"N.i.l"},ID(0),Score(0){}
	void Input_Data(){
		Input();
		fstream f("Participant.dat",ios::app| ios::binary);
        f.write((char*)&*this,sizeof(*this));
        f.close();
	}
	static void Output_Data(){
        fstream f("Participant.dat",ios::in|ios::binary);
		if(!f){
			cout<<"file not present!"<<endl;
			return;
		}
		unsigned int _ID;
		cout<<"Enter ID to Find Record: ";
		cin>>_ID;
		Participant obj;
		while(f.read((char*)&obj,sizeof(obj))){
			if (_ID==obj.ID){
		    	obj.Display();
				break;
			}
		}
        f.close();
    }
    static void Max_Score(){
        fstream f("Participant.dat",ios::in|ios::binary);
		if(!f){
			cout<<"file not present!"<<endl;
			return;
		}
		Participant obj,max;
		while(f.read((char*)&obj,sizeof(obj)))
			if(obj.Score>max.Score)
				max=obj;
        f.close();
        max.Display();
    }
};
int main(){
//	Participant p1,p2,p3;
//	cout<<"p1 obj:-\n";
//	p1.Input_Data();
//	cout<<"p2 obj:-\n";
//	p2.Input_Data();
//	cout<<"p3 obj:-\n";
//	p3.Input_Data();
//	cout<<endl<<endl;
	Participant::Output_Data();
	cout<<"\n\nParticipant having Max Score:-\n";
	Participant::Max_Score();
	return 0;
}
