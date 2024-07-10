#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    //creation
    unordered_map<string, int> m;

    //insertion
    pair<string, int> p = make_pair("vansh", 1);
    m.insert(p);


    cout<<m["vansh"]<<endl;
    return 0;
}