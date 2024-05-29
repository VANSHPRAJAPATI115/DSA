#include <iostream>
using namespace std;
int fact(int n){
    //base cond.
    if(n==0){
        return 1;
    }

    return n*fact(n-1);
}
int main(){
    int n;
    cout<<"Enter value n= ";
    cin>>n;
    cout<<fact(n)<<endl;

    return 0;
}