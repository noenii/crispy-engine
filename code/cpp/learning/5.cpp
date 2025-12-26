#include <iostream>
#include <string>

using namespace std;

void say_hi();
void country(string country="JP");      // funcs are the same, but with the addition of default parameters
void meth(bool y,int &num1,int num2);   // you can also pass references, arrays and structs

// and function overloading, functions can have the same name if they have different types or number of parameters
// local scope is the same too...

int sum(int k);     // recursion too

int main(){
    auto message=[](){      // lambda...
        cout<<"Hello World!\n";
    };

    say_hi();
    country("earth");
    country();
    int smth=20;
    meth(true,smth,20);
    cout<<smth<<"\n";
    cout<<sum(67)<<"\n";
    
    return 0;
}

void say_hi(){
    cout<<"hi"<<"\n";
}

void country(string country){
    cout<<country<<"\n";
}

void meth(bool y,int &num1,int num2){
    if(y){
        num1+=num2;
    }   else{
        num1-=num2;
    }
}

int sum(int k){
  if(k>0){return k+sum(k-1);}
  else{return 0;}
}