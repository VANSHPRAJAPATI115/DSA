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
        for (int j = 1; j <= m; j++)
        {
        if(j==1||j==m){
            cout<<"*";
        }
        else if(i==1||i==n){
            cout<<"*";
        }
        else{
            cout<<" ";
        }

        }
        cout<<endl;
    }
    return 0;
}
