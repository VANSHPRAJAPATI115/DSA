#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<"element at Top "<<pq.top()<<endl;
    pq.pop();
    cout<<"element at Top "<<pq.top()<<endl;
    return 0;
}
