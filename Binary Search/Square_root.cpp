#include<iostream>
using namespace std;
int Square(int n){
    int s=0;
    int e=n;
    int mid = (s+e)/2;
    int ans = -1;
    while(s<=n){
        int square = mid*mid;
        if(square==n){
            return mid;
        }
        if(square<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = (s+e)/2;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter Number= ";
    cin>>n;
    cout<<Square(n);
return 0;
}