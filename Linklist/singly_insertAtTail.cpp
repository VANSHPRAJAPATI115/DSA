#include<iostream>
using namespace std;
class Node{
 public:
 int data;
 Node*next;

 Node(int data){
    this->data=data;
    this->next=NULL;
 }
 };


    void insertAtTail(Node* &tail, int d){
        Node* temp= new Node(d);
        tail->next=temp;
        tail=tail->next;
    }

    void print(Node* &head){
        Node* point=head;
        while(point!=NULL){
            cout<<point->data<<" ";
           point = point->next;
        }
    }
    
int main(){

    Node* node1 = new Node(10);
        Node* head=node1;

    Node* tail=node1;
    insertAtTail(tail,12);
    insertAtTail(tail,15);
    print(tail);
    
}