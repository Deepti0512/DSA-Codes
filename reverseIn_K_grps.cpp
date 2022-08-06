#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
       this->data = data;
       this->next = NULL;
    }
};
void push_back(Node* &head,Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* Kreverse(Node* &head, int k){
    //base case
    if(head == NULL){
        return head;
    }
    //reverse k nodes
    int count = 0;
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while( curr!= NULL && count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // use recursion for reversing the rest of the nodes in groups of k
    if(forward != NULL){
        head->next = Kreverse(forward, k);
    }
    // prev is now pointing to the head of reversed list
    head = prev;
    return prev;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    for(int i=2; i<=10;i++){
        push_back(head,tail,i*10);
    }
    print(head);
    Kreverse(head,2);
    print(head);
    Node* revK2 = Kreverse(head,3);
    print(revK2);
    return 0;
}