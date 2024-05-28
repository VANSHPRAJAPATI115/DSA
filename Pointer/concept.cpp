#include <iostream>
using namespace std;
int main(){
    int i = 3;
    int *ptr = &i;
    cout<<(*ptr)++<<endl;
    cout<<*ptr<<endl;

    ptr = ptr+1;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    return 0;
}