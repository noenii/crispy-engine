#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    // builtin math funcs
    cout<<max(6,7)<<"\n";
    cout<<min(9,11)<<"\n";

    // from cmath
    cout<<sqrt(64)<<"\n";
    cout<<round(2.6)<<"\n";
    cout<<log(2)<<"\n";

    // booleans
    cout<<boolalpha;    // enable printing out boolean values
    bool isCPPHard=true;
    cout<<isCPPHard<<"\n";
    cout<<noboolalpha;   // disable boolalpha

    // bool operations are the same as c
    // same with logic
    if(isCPPHard){
        cout<<"then quit"<<"\n";    // nah id win
    }   // switch statements are also the same

    while(true){
        break;
    }

    for(int i=1;i<101;i++){
        if(i%15==0){
            cout<<"fizzBuzz\n";
        }   else if(i%3==0){
            cout<<"fizz\n";
        }   else if(i%5==0){
            cout<<"buzz\n";
        }   else{
        cout<<i<<"\n";
        }
    }

    string arr[3]={"smth", "smth else", "another thing"};   // regular array stuff
    for(string num:arr) {
        cout<<num<<"\n";    // special loop for looping through arrays
    }

    // arrays are static tho, vectors are the dynamic version
    vector<int> numbers={21};   // seems a bit complicated for beginners, so ill learn more later

    cout<<sizeof(arr)<<"\n";    // size of array
    // multi dimensional arrays are also supported, duh
    return 0;
}