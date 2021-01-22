#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class employee{
protected:
    string type;
    int available_bed;
    char employee_type;
    string name;
    int age;
    int date_of_join;
    
    virtual void FReadMore(ifstream&)=0;	
	virtual void FWriteMore(ofstream& output)=0;
	virtual void ReadMore(istream&)=0;
	virtual void WriteMore(ostream& output)=0;
	

	employee(){}
    virtual ~employee(){}

    friend ifstream& operator>>(ifstream& input, employee &p){
        input >> p.type;
        input >> p.available_bed;
        input >> p.employee_type;
        input >> p.name;
        input >> p.age;
        input >> p.date_of_join;
        p.FReadMore(input);
        return input;
    }
	
	friend ofstream& operator<<(ofstream& output, employee &p){
        output << p.type<<" "<< p.available_bed<<" "<< p.employee_type<<" ";
        output << p.name<<" " << p.age<<" "<< p.date_of_join<<" ";
        p.FWriteMore(output);
        return output;
    }
	friend istream& operator>>(istream& input, employee &p){
		std::cout << "Enter department type (string): ";
        input >> p.type;
        std::cout << "Enter available bed: ";
        input >> p.available_bed;
        std::cout << "Enter type of employee (char): ";
        input >> p.employee_type;
        std::cout << "Enter employee name (string): ";
        input >> p.name;
        std::cout << "Enter age: ";
        input >> p.age;
        std::cout << "Enter date of join: ";
        input >> p.date_of_join;
        p.ReadMore(input);
        return input;
    }
	
	friend std::ostream& operator<<(ostream& output, employee &p){
        output << p.type<<" "<< p.available_bed<<" "<< p.employee_type<<" ";
        output << p.name<<" " << p.age<<" "<< p.date_of_join<<" ";
        p.WriteMore(output);
        return output;
    }
    
    void read(string filename){
    	ifstream in(filename.c_str());
		in>>*this;
		//if you want to use read: 
		//in.read(reinterpret_cast<const char*>(&e),sizeof(e));
		in.close();	
	}
	void write(string filename){
		ofstream out(filename.c_str());
		out<<*this<<endl;
		out.close();
	}
friend class over;
};

class special_employee : public employee{
	int extra_data;
	
	special_employee(){}
	
	void FReadMore(ifstream& input) override{
         input >> extra_data;
    }
    void FWriteMore(std::ofstream& output) override{
        output << extra_data<<" ";
    }
    void ReadMore(std::istream& input) override{
    	cout << "Enter Extra data: ";
        input >> extra_data;
    }
    void WriteMore(std::ostream& output) override{
		output << extra_data<<" ";
    }

friend class over;
};

class over{
public:
	static void func(){
		employee **emp_ptr=new employee*[3];
    	emp_ptr[0] =new special_employee;
		emp_ptr[1]=new special_employee;
	    cin >> *emp_ptr[0];
		emp_ptr[0]->write("emp.txt");
		emp_ptr[0]->write("emp.txt");
		emp_ptr[1]->read("emp.txt");
	   
	   cout <<"input data to file: "<< *emp_ptr[0]<<endl;
	   cout <<"retrieve data from file: "<< *emp_ptr[1];
	}
};
int main()
{
    over::func();
}
