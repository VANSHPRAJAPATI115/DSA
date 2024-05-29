#include <iostream>
using namespace std;
int count(int n){
    //base cond.
    if(n==0){
        return 0;
    }

    return n+count(n-1);
}
int main(){
    int n;
    cout<<"Enter value n= ";
    cin>>n;
    cout<<count(n)<<endl;

    return 0;
}