#include<iostream>
using namespace std;
class Meal{
	string Name;
    unsigned int Calorie_Count;
public:
	Meal(string Name="No Name Provided!\a",unsigned int Calorie_Count=0):Name(Name),Calorie_Count(Calorie_Count){}

	friend istream& operator>>(istream& in,Meal& obj){
	    cout<<"Enter Meal Name: ";
	    in>>obj.Name;
	    cout<<"Enter Calories: ";
	    in>>obj.Calorie_Count;
	    return in;
	}
	friend ostream& operator<<(ostream &out,const Meal &obj){
	    out<<"Meal Name: "<<obj.Name<<endl
		   <<"Calories: "<<obj.Calorie_Count<<endl; 
	    return out;
	}
	Meal operator+(Meal Summary_Meal_obj){
		Summary_Meal_obj.Name="\b\b\b\b\b\b\b\b\b\b\b\b\bDaily Total: "+Name+", "+Summary_Meal_obj.Name;
        Summary_Meal_obj.Calorie_Count+=Calorie_Count; 
        return Summary_Meal_obj; 
    }
};
int main(){
	Meal obj1("Pizza",5000),obj2("Burger",1000),obj3;
	cout<<"Input Obj 3:-\n";
	cin>>obj3;
	cout<<"\nDisplay Obj 1:-\n";
	cout<<obj1;
	cout<<"\nDisplay Obj 2:-\n";
	cout<<obj2;
	cout<<"\nDisplay Obj 3:-\n";
	cout<<obj3;
	cout<<"\nMeal Summary:-\n";
	cout<<obj1+obj2+obj3;
	return 0;
}
