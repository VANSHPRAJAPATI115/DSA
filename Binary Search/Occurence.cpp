#include <iostream>
using namespace std;

    int Occurence(int arr[], int n, int key){
        
        int start=0;
        int end=n-1;
        int mid = end+(end-start)/2;
        while(start<=end){
            if(arr[mid]==key){
                return mid;
            }
            else if(key>arr[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
                    int mid = end+(end-start)/2;

        }
        return mid;
        
    }

int main(){
    int n,key;
    cout<<"Enter Size = ";
    cin>>n;
    int arr[n];
    cout<<"Enter Key Value= ";
    cin>>key;
    cout<<"Enter Array Value = ";
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i]; 
    }
   cout<<Occurence(arr,n, key)<<endl;
     
    
    return 0;
}