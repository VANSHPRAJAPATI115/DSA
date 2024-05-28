#include <iostream>
using namespace std;
int main(){
   int arr[10]={1,2,3};
   cout<<arr<<endl;//same op
   cout<<&arr[0]<<endl;// same op
   cout<<&arr<<endl;// same op
   cout<<*arr<<endl;//1

   cout<<sizeof(arr)<<endl;//40

   int *p=&arr[0];
   cout<<sizeof(p)<<endl;//4
   cout<<sizeof(*p)<<endl;//4 dependend on machine
    return 0;
}