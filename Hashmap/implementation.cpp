#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    //creation
    unordered_map<string, int> m;

    //insertion
    //1
    pair<string, int> p = make_pair("vansh", 1);
    m.insert(p);

    //2
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    //3
    m["mera"]=3;


    cout<<m["vansh"]<<endl;
    cout<<m["love"]<<endl;
    cout<<m["mera"]<<endl;
    return 0;
}