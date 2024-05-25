#include <iostream>
using namespace std;

    bool search(int arr[], int n, int key){
        
        for (int i = 0; i < n; i++)
        {
            if(arr[i]==key){
                return true;
            }
           
        }
        
        return false;
    }

int main(){
    int n, key;
    cout<<"Enter Size = ";
    cin>>n;
    int arr[n];
    cout<<"Enter Key you have find sequence = ";
    cin>>key;
    cout<<"Enter Array Value = ";
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i];      
    }
   int temp= search(arr,n,key);
     if(temp==true){
        cout<<"key found";
     }
     else{
        cout<<"Not found";
     }
    
    return 0;
}