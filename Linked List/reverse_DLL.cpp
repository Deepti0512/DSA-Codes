#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node* prev;
   Node* next;

   Node(int data){
       this->data = data;
       this->next = NULL;
       this->prev = NULL;
    }

};

void insertAtHead(Node* &head,Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head,Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        temp->next = NULL;
        tail = temp;
    }
}

void printRreverse1(Node* head,Node* tail){
   Node* temp = tail;
   while(temp!=NULL){
       cout<<temp->data<<" ";
       temp = temp->prev;
   }
   cout<<endl;
}

Node* reverse2(Node* &head, Node* &tail){
    if(head == NULL || head->next == NULL){
    return head;
    }
    Node* previous = NULL;
    Node* current = head;
    Node* store = head;
    while(current!=NULL){
        Node* forward = current->next;
        current -> next = previous;
        current -> prev = forward;
        previous = current;
        current = forward;
    }
    head = previous;
    tail = store;
return head;
}

Node* reverse3(Node* &head, Node* &tail){
    Node* store = head;
    Node* temp = NULL;
    Node* curr = head;
    //logic: swapping prev and next pointer of each node
    while(curr!=NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    
    head = temp->prev;
    tail = store;
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
Node* head = NULL;
Node* tail = NULL;
insertAtHead(head,tail,10);
insertAtTail(head,tail,20);
insertAtTail(head, tail, 30);
insertAtTail(head,tail,40);
insertAtTail(head,tail,50);
cout<<"original linked list: "<<endl;
print(head);
cout<<"head->data: "<<head->data<<endl;
cout<<"tail->data: "<<tail->data<<endl;
cout<<"Printing linked list in reverse order without actually reversing the linked list: "<<endl;
printRreverse1(head, tail);
Node* RDLL = reverse2(head,tail);
cout<<"Linked list after 1st reverse operation: "<<endl;
print(RDLL);
Node* rev = reverse3(head,tail);
cout<<"Linked list after 2nd reverse operation: "<<endl;
print(rev);
cout<<"head->data: "<<head->data<<endl;
cout<<"tail->data: "<<tail->data<<endl;
return 0;
}
