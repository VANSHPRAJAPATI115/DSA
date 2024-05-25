#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter Number : ";
    cout<<"Enter a = ";
    cin>>a;
    cout<<"Enter b = ";
    cin>>b;
    cout<<"Enter c = ";
    cin>>c;
    
    if(a>b){
        if(a>c){
            cout<<"a is greater value is a ";
            cout<<a;
        }
        else{
            cout<<"c is greater value is c ";
            cout<<c;
        }
    }
    else{
        if(b>c){
            cout<<"b is greater value is b ";
            cout<<b;
        }
        else{
            cout<<"c is greater value is c ";
            cout<<c;
        }
    }

    return 0;
}