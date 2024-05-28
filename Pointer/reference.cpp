#include <iostream>
using namespace std;
void update(int *p){
    p=p+1;
    *p=*p+1;
    cout<<"inside function "<<p<<endl;
}
// void without_reference(int p){
//     cout<<"inside function "<<*p<<endl;
// }Not used this type
int main(){
    int i = 3;
    int *p = &i;
    cout<<"Before "<<p<<endl;
    update(p);
        cout<<"After "<<p<<endl;
    cout<<"After "<<*p<<endl;


    return 0;
}