#include<iostream>
using namespace std;
class Student{
	unsigned char quiz_1,quiz_2,mid_term,final_exam; //i.e. unsigned char range (0-255)
	float overall_score;
	
	void overall_score_percentage(){ //i.e. secure calculations
		overall_score=quiz_1+quiz_2+((float)mid_term/5)+((float)final_exam/2);
	}
	char final_grade() const{ //i.e. private-> data abstraction
		if (overall_score>=90)
		return 'A';
		else if(overall_score>=80&&overall_score<90)
		return 'B';
		else if(overall_score>=70&&overall_score<80)
		return 'C';
		else if(overall_score>=60&&overall_score<70)
		return 'D';
		else
		return 'F';
	}
	void validating_input_data(string str,unsigned char limit,unsigned char *data) const{ //i.e. generic function for validating input data
		unsigned short temp; //i.e. unsigned int range (0-65,535)
		while(1){
			cout<<"Enter points of "<<str<<": ";
			cin>>temp;	
			if (temp>=0&&temp<=limit){
			*data=temp;
			break;
			}
			cout<<"Re-\a";
		}
	}
public:
	Student():quiz_1{0},quiz_2{0},mid_term{0},final_exam{0},overall_score{0} {} //i.e. initialization

	void input_data(){ //i.e. data abstraction
		cout<<"INPUT DATA:\n";
		validating_input_data("Quiz 01",15,&quiz_1);
		validating_input_data("Quiz 02",15,&quiz_2);
		validating_input_data("Mid Term",100,&mid_term);
		validating_input_data("Final Exam",100,&final_exam);
		overall_score_percentage();
	}
	void display_data() const{
		cout<<"\nDISPLAY DATA:"<<endl
			<<"Your points in Quiz 01 are: "<<(short)quiz_1<<endl
			<<"Your points in Quiz 02 are: "<<(short)quiz_2<<endl
			<<"Your points in Mid Term are: "<<(short)mid_term<<endl
			<<"Your points in Final Exam are: "<<(short)final_exam<<endl
			<<"Overall Score is: "<<overall_score<<"%"<<endl
			<<"Final Grade is: "<<final_grade()<<" Grade "<<endl;
	}
};
int main(){
	Student marksheet;
	marksheet.input_data();
	marksheet.display_data();
    return 0; 
}

