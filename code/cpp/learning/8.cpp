#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main(){
    ofstream text("txt.txt");
    text<<"does it work?\n";
    
    text.close();

    string str;
    ifstream txt("txt.txt");
    while(getline(txt, str)){
        cout<<str<<"\n";
    }
    txt.close();

    time_t now;
    time(&now);
    now=time(NULL);
    cout<<now<<"\n";
    
    /*
        try{
            int x=10/0;
        }
        catch(...){
            cout<<"error\n";
        }
    */
    
    return 0;
}