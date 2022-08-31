#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(){
        //default constructor
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for node with data "<<val<<endl;
    }
};

int length(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
  return count;
}

void InsertAtHead(Node* &head,Node* &tail,int d){
    // in case of empty linked list
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
    }
}

void InsertAtTail(Node* &head,Node* &tail,int data){
    // in case of empty list
    if(tail==NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(data);
        tail->next=temp;
        tail = temp;
    }
}

void InsertAtPosition(Node* &head, Node* &tail, int position, int data){
    int size = length(head);
    if(position > size){
        cout<<"Invalid position!!\n";
        cout<<"Enter position upto "<<size<<endl;
        return;
    }
    if(position == 1){
     InsertAtHead(head,tail,data);
     return;
    }
    int cnt = 1;
    Node* temp = head;
    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    } 
    if(temp->next == NULL){
        InsertAtTail(head,tail,data);
        return;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

int getvalue(Node* head,int pos){
   if(pos == 0){
       return head->data;
   }
   else{
       int count = 0;
       Node* temp = head;
       while(count < pos){
           temp = temp->next;
           count++;
       }
       return temp->data;
   } 
}

Node * getnode(Node* head, int pos){
    if(pos == 0){
       return head;
   }
   else{
       int count = 0;
       Node* temp = head;
       while(count < pos){
           temp = temp->next;
           count++;
       }
       return temp;
   } 
}

void swap(Node* &n1, Node* &n2){
    int temp = n1->data; 
    n1->data = n2->data;
    n2->data = temp;
}

void reverse1(Node* &head,Node* &tail){
   // logic: by swapping data
   int size = length(head);
   for(int i = 0, j = size-1; i < size/2; i++, j--){
     Node* n1 = getnode(head,i);
     Node* n2 = getnode(head,j);
     swap(n1,n2);
   }
}

Node* reverse2(Node* &head){
  //logic: by changing pointers to nodes
  if(head == NULL || head->next == NULL){
    return head;
  }
  Node* prev = NULL;
  Node* curr = head;
  while(curr!=NULL){
    Node* forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }
  head = prev;
  return prev;
}

//reverse using recursion
Node* reverse3(Node* head){
    //base case
    if(head == NULL || head->next == NULL){
       return head;
    }
    Node* chotaHead = reverse3(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<'\n';
}

int main(){
    //Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    InsertAtHead(head,tail,5);
    InsertAtPosition(head,tail,1,2);
    InsertAtPosition(head,tail,2,12);
    InsertAtTail(head,tail,15);
    InsertAtTail(head,tail,17);
    InsertAtTail(head,tail,20);
    InsertAtTail(head,tail,22);
    InsertAtHead(head,tail,-1);
    InsertAtTail(head,tail,25);
    InsertAtPosition(head,tail,1,-3);
    
   // cout<<"Original LInked LIst: ";
    print(head);
   // reverse1(head,tail);
   // cout<<"\nLinked list after reversing using function reverse1 that uses the logic of swapping data values: ";
   // print(head);
   // Node* revLL = reverse2(head);
   // cout<<"\nResult after reversing using function reverse2 (iterative func which changes pointer direction): ";
   // print(revLL);
   // Node* ans = reverse3(head);
   // print(ans);
    return 0;
}