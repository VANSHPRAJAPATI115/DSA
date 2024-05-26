#include <iostream>
using namespace std;

    int unique(int arr[], int n){
        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            ans = ans^arr[i];         
        }
        for (int i = 1; i < n; i++)
        {
            ans = ans^i;         
        }
        
        return ans;
        
    }

int main(){
    int n, key;
    cout<<"Enter Size = ";
    cin>>n;
    int arr[n];
    cout<<"Enter Array Value = ";
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i];      
      
    }
   cout<<unique(arr,n);
     
    
    return 0;
}