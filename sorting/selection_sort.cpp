#include <iostream>
using namespace std;

    void selection(int arr[], int n){
        for(int i=0; i<n-1; i++){
            int min_index=i;
            for(int j=i+1; j<n; j++){
                if(arr[min_index]>arr[j]){
                    min_index= j;

                }
            }
            swap(arr[min_index],arr[i]);
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
   selection(arr,n);
     
    
    return 0;
}