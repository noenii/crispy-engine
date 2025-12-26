#include <iostream>
#include <string>

using namespace std;

class person {
    public:
        void print_info(string str){
            cout<<str<<"\n";
        }
        void gpa_check(person p);
        string name;
        int age;
        float gpa;
};

void person::gpa_check(person p){
    if(p.gpa>=3.5){cout<<"its aight\n";}
    else{cout<<"hell no\n";}
}

class person2 {
    public:
        person2(string a,int b,float c,string d, string e);
        void print_c(){
            cout<<country<<"\n";
        }
        void print_a(){
            cout<<address<<"\n";
        }
        friend void display(person2);
        string name;
        int age;
        float gpa;
    protected:      // like private but can be accessed in inherited classes
        string country;
    private:        // cannot be accessed 
        string address;
};

void display(person2 emp) {
    cout<<"Salary: "<<emp.country<<"\n";
}

person2::person2(string a,int b,float c,string d,string e){   // you can also overload constructors, same as functions
    name=a,age=b,gpa=c,country=d,address=e;
}

int main(){
    person me;
    me.age=16;
    me.name="aki";
    me.gpa=4.0;
    me.print_info(me.name);
    me.gpa_check(me);       // ok icl ts is fire

    person2 me2("yun-seo",16,4.1,"who's asking :/","earth");
    cout<<me2.name<<","<<me2.age<<","<<me2.gpa<<"\n";

    me2.print_a();  // use getter and setter methods to deal with private/protected data
    display(me2);   // friend function to access private/protected data

    return 0;
}