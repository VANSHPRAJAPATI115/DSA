#include <iostream>
using namespace std;
int pow(int n){
    //base cond.
    if(n==0){
        return 1;
    }

    return 2*pow(n-1);
}
int main(){
    int n;
    cout<<"Enter value n= ";
    cin>>n;
    cout<<pow(n)<<endl;

    return 0;
}