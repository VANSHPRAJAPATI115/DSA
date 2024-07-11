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
    //first time output terminate
    // cout<<m.at("unknown")<<endl;
    cout<<m["unknown"]<<endl;
    cout<<m.at("unknown")<<endl;

    m.erase("love");
    cout<<m.size()<<endl;
    m.erase("unknown");
    cout<<m.size()<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    unordered_map<string, int>:: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }



    return 0;
}