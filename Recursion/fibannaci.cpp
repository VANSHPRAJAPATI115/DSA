#include <iostream>
using namespace std;
int fib(int n){
    //base cond.
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    int ans = fib(n-1)+fib(n-2);
    return ans;
}
int main(){
    int n;
    cout<<"Enter value n= ";
    cin>>n;
    cout<<fib(n)<<endl;

    return 0;
}