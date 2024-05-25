#include <iostream>
using namespace std;

    void reverse(int arr[], int n){
        int start = 0;
        int end = n-1;
        for (int i = 0; i < n; i++)
        {
            if(start<=end){
                swap(arr[start],arr[end]);
                start++;
                end--;
            }
                    cout<<arr[i];

           
        }
    
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
   reverse(arr,n);
     
    
    return 0;
}