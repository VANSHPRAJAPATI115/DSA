#include<iostream>
using namespace std;
bool check(string &name, int s, int e){
    if(s>e){
        return true;
    }

    if(name[s]!=name[e]){
        return false;
    }
    else{
        return check(name, s++, e--);
    }
   
    
}
int main(){
    string name = "abcba";
    int num  = check(name,0,name.length()-1);
    if(num){
        cout<<"palindrome"<<endl;
    }
    else{
        cout<<"not palindrome"<<endl;
    }
    return 0;
}