#include <iostream>
using namespace std;

    int sum(int arr[], int n){
        int sum=0;
        for (int i = 0; i < n; i++)
        {
            sum = sum+arr[i];
        }
        return sum;
        
    }

int main(){
    int n;
    cout<<"Enter Size:-";
    cin>>n;
    int arr[n];
    cout<<"Enter Array Value:-";
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i]; 
      
    }
   cout<<sum(arr,n)<<endl;
     
    
    return 0;
}