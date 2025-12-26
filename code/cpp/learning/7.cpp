#include <iostream>
#include <string>

using namespace std;

class vehicle{
    public:
        string brand="ford";
        virtual void honk(){    // virtual is for functions that can be overridden in inherited classes
            cout<<"Tuut, tuut!\n";
        }
};

// Derived class
class car:public vehicle{
    public:
        string model="Mustang";
        void honk(){
            cout<<"Mustang: Tuut, tuut!\n";
        }
};

template <typename t>

t my_func(t a, t b){    // function template
    return a+b;
}
template <typename a>   // class template
class smth{
    public:
        a a;    // could be anything
};

int main(){
    car c;
    cout<<c.model<<"\n";  // the regular inheritance bs
    // and polymorphism
    // and -> to access data thru pointers

    cout<<my_func<int>(6,7)<<"\n";      // a template is for writing functions or classes for different data types

    return 0;
}