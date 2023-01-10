#include <iostream>
#include <fstream>
using namespace std;

class Participant{
    int id, score;
    char name[25];

    public:
    Participant(){}
    
    void getdata(){
        cout << "Enter Name ID and Score (separated by string): ";
        cin >> name >> id >> score;
    }
    int getID(){
        return this->id;
    }
    string getName(){
        return this->name;
    }
    int getScore(){
        return this->score;
    }

    void Input(){
        fstream fout("participant.dat", ios::app | ios::binary);
        Participant p;
        p.getdata();
        fout.write((char*)&p, sizeof(p));
        fout.close();
    }

    void Output(){  
        int searchID;     
        cout << "Enter the ID of the participant to search the file for: ";
        cin >> searchID;
        fflush(stdin);
        fstream fin("participant.dat", ios::in | ios::binary);
        Participant p;
        while(!fin.eof()){
            fin.read((char *) &p, sizeof(p));
            if(p.getID() == searchID){
                cout
                    << "ID: " << p.getID() << endl
                    << "Name: " << p.getName() << endl   
                    << "Score: " << p.getScore() << endl;  
                fin.close();  
                break;   
            }
        }
    }

    void Max(){
        int highest = 0;
        fstream fin("participant.dat", ios::in | ios::binary);
        Participant p;
        while(!fin.eof()){
            fin.read((char *) &p, sizeof(p));
            if(p.getScore() > highest)
                highest = p.getScore();
        }
        cout << "Highest score earned by a participant: " << highest;
    }
};


int main(){
    Participant p;
    char choice = 'n';
    do {
        p.Input();
        cout << "Do you want to add another participant? (Y or N): ";
        cin >> choice;
        fflush(stdin);
    } while (choice == 'y' || choice == 'Y');
   
    p.Output();
    p.Max();
    pause();
}
