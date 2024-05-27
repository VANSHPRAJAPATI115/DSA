#include <iostream>
using namespace std;

    void bubble(int arr[], int n){
        for(int i=1; i<n; i++){
            int temp = arr[i];
            int j=i-1;
            for(; j>=0; j--){
                if(arr[j]>temp){
                 arr[j+1]=arr[j];
                }
                else{
                    break;
                }
            }
            arr[j+1]=temp;
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