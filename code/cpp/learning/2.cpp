#include <iostream>
#include <string>

using namespace std;

int main(){
    cout<<"start of program\n";

    string user="noenii";
    string name="aki";
    string both=user+" | "+name;
    cout<<both;     // string concatenation =D

    // + is used for adding and concatenation, if you try int + str you will get an error
    // better than automatically type casting, unlike some other lang *cough* js *cough*

    cout<<"\n"<<both.length();  //str len
    // string indexing too
    cout<<both[6];  //no out of bounds check tho :/

    // you can also change characters on index

    string text;
    cin>>text;
    cout<<"\nyou entered: "<<text<<"\n";
    // basically scanf, does not fw white space
    
    string txt;
    getline(cin, txt);
    getline(cin, txt);
    cout<<"\nyou entered: "<<txt<<"\n";

    char traditionalWay[]="the better way";
    cout<<traditionalWay<<"\n";     // jst like c

    return  0;
}