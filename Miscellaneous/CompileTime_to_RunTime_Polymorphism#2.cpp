#include<iostream>
#include<memory>
using namespace std; 
class IAnimal{
public:
    virtual ~IAnimal(){} //i.e. virtual dtor-> to trigger derived class dtor
    
    virtual void makeSound()const=0;
};
class Dog:public IAnimal{  
public:
    virtual ~Dog()override{} //i.e. for reverse order dtor call
	 
    virtual void makeSound()const override{ //i.e. override-> generates error if the func is not overriden
        cout << "\nWoof Woof" << endl;
    } 
    string toString()const{
        return "Dog";
    }
};
class Cat:public IAnimal{ 
public:
    virtual ~Cat()override{}
    
    virtual void makeSound()const override{
        cout << "\nMeowwwww" << endl;
    }
};
class Robot{
public:
    std::string toString()const{
        return "Robot";
    }
};
template<typename T,typename... Args>
unique_ptr<T>make_unique(Args&&... args) {
    return unique_ptr<T>(new T(forward<Args>(args)...));
}
class ThingWithToString{
public:
    template<typename T>
    ThingWithToString(const T& obj):inner(make_unique<Holder<T> >(obj)){}
    
    ThingWithToString(const ThingWithToString& that):inner(that.inner->clone()){}
    ThingWithToString& operator=(const ThingWithToString& that){
        if (this != &that)
        inner=that.inner->clone();
        return *this;
    }
    string toString()const{
        return inner->toString();
    }
private:
    struct HolderBase{
        virtual ~HolderBase() { }
        virtual string toString()const=0;
        virtual unique_ptr<HolderBase>clone()const=0;
    };

    template<typename T>
    struct Holder:public HolderBase {
        Holder(const T& obj): obj_(obj){}

        string toString() const override{
            return obj_.toString();
        }

        unique_ptr<HolderBase> clone() const override{
            return make_unique<Holder<T> >(obj_);
        }
        
        T obj_;
    };
    unique_ptr<HolderBase>inner;
};
ThingWithToString getThingWithToString(int which){
    switch (which){
        case 1:
		return ThingWithToString(Dog());
        case 2:
        return ThingWithToString(Robot());
        default:
        throw runtime_error("Unknown object type");
    }
}    
int main(){
    int which;
    cout<<"Which class funcion u want to invoke?\n1) Dog Sound\n2) Cat Sound\n==>";
    cin>>which;
    ThingWithToString object=getThingWithToString(which);
    cout<<endl<<object.toString()<<endl;
    return 0;
}
