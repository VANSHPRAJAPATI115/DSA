#include <iostream>
using namespace std;
int main(){
    int n, m;
    cout<<"Enter Row :";
    cin>>n;
    cout<<endl;

    cout<<"Enter Col :";
    cin>>m;
    cout<<endl;
    for(int i=1; i<=n; i++){
        for (int j = 1; j <= i; j++)
        {
        if((i+j)%2==0){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
        }
        cout<<endl;
    }
    return 0;
}