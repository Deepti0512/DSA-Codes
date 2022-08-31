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
void InsertAtHead(Node* &head,Node* &tail,int data){

    // if empty list
    if(head == NULL){
      Node *temp = new Node(data);
      head = temp;
      tail = temp;
    }

    else{
     Node* temp = new Node(data);
     temp->next=head;
     head->prev = temp;
     head = temp;
    }
}
void InsertAtTail(Node* &head,Node* &tail,int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else{
      Node* temp = new Node(data);
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
}
void InsertAtPosition(Node* &head, Node* &tail, int data,int position){
    //for inserting at head(1st position/beginning)
    if(position == 1){
        InsertAtHead(head,tail,data);
        return;
    }
    //for inserting at middle or end
    int count = 1;
    Node* temp = head;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    if(temp->next==NULL){
        InsertAtTail(head,tail,data);
        return;
    }
    else{
        Node* nodetoinsert = new Node(data);
        
        nodetoinsert->next = temp->next;
        temp->next->prev = nodetoinsert;
        temp->next = nodetoinsert;
        nodetoinsert->prev = temp;

    }
}

void Print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
       cout<<temp->data<<" ";
       temp = temp->next;
    }
    
}
void deleteFromPosition(Node* &head, Node* &tail, int position){
  
  if(position == 1){
      Node*temp = head;
      temp->next->prev = NULL;
      head = temp->next;
      temp->next = NULL;
      delete temp;
    }
   else{
       int count = 1;
        Node* current = head;
        Node* previous = NULL;
       while(count < position){
          previous = current;
          current= current->next;
          count++;
        }
        //To delete last node
        if(current->next == NULL){
            current->prev = NULL;
            previous->next = current->next;
            tail = previous;
            delete current;
        }
        // To delete middle node
        else{
          current->next->prev = previous;
          current->prev = NULL;
          previous->next = current->next;
          current->next = NULL; 
          delete current;
        }
   }
}
int main(){
   // Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    InsertAtHead(head,tail,5);
    InsertAtTail(head,tail,15);
    InsertAtPosition(head,tail,7,2);
    InsertAtTail(head,tail,20);
    cout<<"The elements of Doubly linked list are: ";
    Print(head);
    cout<<"\nhead: "<<head->data<<" tail: "<<tail->data<<endl;
    deleteFromPosition(head,tail,1);
    Print(head);
    cout<<"\nhead: "<<head->data<<" tail: "<<tail->data<<endl;
    cout<<"The code so far is working properly!"<<endl;
    return 0;
}

// The code so far is working properly!!
