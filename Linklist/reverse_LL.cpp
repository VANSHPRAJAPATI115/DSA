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

Node* reverse(Node* head) {

    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;  // Save the next node
        curr->next = prev;     // Reverse the current node's pointer
        prev = curr;           // Move prev and curr one step forward
        curr = forward;
    }
    return prev;  // Prev will be the new head after the loop ends
}

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev=NULL;
//         ListNode* curr=head;
//         while(curr!=NULL)
//         {
//             ListNode* temp=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=temp;
//         }
//         head=prev;
//         return head;
//     }
// };


// more less run time take


int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 12);
    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail, head, 4, 22);
    print(head);

    // Update head to the new reversed list
    head = reverse(head);

    // Print the reversed list
    cout << "Reversed list: ";
    print(head);

    return 0;
}
