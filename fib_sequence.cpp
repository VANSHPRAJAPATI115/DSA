#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n value :";
    cin>>n;
    int num=0;
    int num1=1;

    for(int i=1; i<n-1; i++){
        int temp=num1;
     num1=num+num1;
        num=temp;
        
        
    }
    cout<<num1;
    
    return 0;
}