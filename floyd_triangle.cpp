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
    int count = 1;
    for(int i=1; i<=n; i++){
        for (int j = 0; j < i; j++)
        {
        cout<<count;
        count++;
        }
        cout<<endl;
    }
    return 0;
}