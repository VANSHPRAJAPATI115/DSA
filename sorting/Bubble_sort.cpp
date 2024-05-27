#include <iostream>
using namespace std;

    void bubble(int arr[], int n){
        for(int i=0; i<n; i++){
        
            for(int j=i+1; j<n; j++){
                if(arr[j]<arr[i]){
                 swap(arr[j],arr[i]);
                }
            }
        }
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        
    }

int main(){
    int n;
    cout<<"Enter Size = ";
    cin>>n;
    int arr[n];
    cout<<"Enter Array Value = ";
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i]; 
    }
   bubble(arr,n);
     
    
    return 0;
}