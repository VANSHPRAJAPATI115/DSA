#include <iostream>
using namespace std;
void print(int *p){
    cout<<"inside function "<<*p<<endl;
}
// void without_reference(int p){
//     cout<<"inside function "<<*p<<endl;
// }Not used this type
int main(){
    int i = 3;
    int *p = &i;
    cout<<"outside function "<<*p<<endl;
    print(p);
    return 0;
}