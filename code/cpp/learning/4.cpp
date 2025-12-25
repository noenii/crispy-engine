#include <iostream>
#include <string>

using namespace std;

int main(){
    struct person{
        string name;
        int age;
    };
    person me;
    me.name="aki",me.age=16;

    cout<<me.name<<" "<<me.age<<"\n";   // structs, cooooooool
    
    enum stuff {
        num1=67,
        num2=21,
        num3=911,
        num4=69,
        num5=68
    };  // enums too

    string thiss="CPP";
    string &notThis=thiss;  // reference is basically an alias for a variable
    // changing the original variable will also change the ref, and vice versa
    cout<<&thiss<<"\n";   // also get the address with the ampersand

    // and pointers
    string* pThis=&thiss;   // same shi as C
    cout<<*pThis<<"\n";     // dereferencing too
    // you can modify values through the pointer too
    // yk, usual memory management

    int* ptr = new int;     // alloc
    *ptr = 68;
    delete(ptr);    // free

    return 0;
}