#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory free= "<<value<<endl;
    }
};

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // If the position is beyond the last node, insert at the tail
    if (temp == NULL || temp->next == NULL) {
        insertAtTail(tail, d);
    } else {
        Node* middle = new Node(d);
        middle->next = temp->next;
        temp->next = middle;
    }
}

void print(Node* head) {
    Node* point = head;
    while (point != NULL) {
        cout << point->data << " ";
        point = point->next;
    }
    cout << endl;
}

    void Deletion(Node* &head, int position){
        if(position == 1){
            Node* temp = head;
            head = head->next;

            temp->next=NULL;
            delete temp;

        }
        else{
            Node* curr=head;
            Node* prev=NULL;
            int cnt = 1;
            while(cnt<position){
                prev = curr;
                curr = curr->next;
                cnt++;
            }
            prev->next=curr->next;
            curr->next = NULL;
            delete curr;
        }
    }

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 12);
   
    insertAtTail(tail, 15);
    print(head);
    insertAtPosition(tail, head, 4, 22);
    print(head);

    Deletion(head, 4);
    print(head);
    cout << "Head data: " << head->data << endl;
    cout << "Tail data: " << tail->data << endl;

    return 0;
}
