#include<iostream>
#include<memory>
using namespace std;
class IAnimal{
public:
    virtual ~IAnimal(){ //i.e. virtual dtor-> to trigger derived class dtor
		cout << "\nAnimal dtor" << endl;
	}
    virtual void makeSound()const=0;
};
class Dog:public IAnimal{  
public:
    virtual ~Dog()override{ //i.e. for reverse order dtor call 
		cout << "\nDog dtor" << endl; 
	}
    virtual void makeSound()const override{ //i.e. override-> generates error if the func is not overriden
        cout << "\nWoof Woof" << endl;
    } 
    string toString()const{
        return "Dog";
    }
};
class Cat:public IAnimal{ 
public:
    virtual ~Cat()override{
		cout << "\nCat dtor" << endl;
	}
    virtual void makeSound()const override{
        cout << "\nMeowwwww" << endl;
    }
};
/*Spicy Secret Sauce (Alternate) for make_unique */
template<typename T,typename... Args> // i.e. typename = class 
unique_ptr<T>make_unique(Args&&... args) { //i.e. variadic template func-> allows us to take multiple different arguments
    return unique_ptr<T>(new T(forward<Args>(args)...)); //i.e. foward ->
}
unique_ptr<IAnimal>getAnimal(int which){
    switch(which){
        case 1:
        return make_unique<Dog>();
        case 2:
        return make_unique<Cat>();
        default:
        throw runtime_error("Unknown animal type");
    }
}
int main(){
    int which;
    cout<<"Which class funcion u want to invoke?\n1) Dog Sound\n2) Cat Sound\n==>";
    cin>>which;
    unique_ptr<IAnimal>animal=getAnimal(which); //i.e. abstract base class ptr pointing to derived class
    animal->makeSound();
    return 0;
}
