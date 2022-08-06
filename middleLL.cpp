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
int length(Node* &head){
    int length = 0;
    Node* temp = head;
    while(temp!= NULL){
        temp = temp->next;
        length++;
    }
    return length;
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
    // to insert at last position there are following two methods
    // 1. using length function(user-defined)
    // if(position == length(head)){
    //     InsertAtTail(head,tail,data);
    //     return;
    // }
    // 2. checking if the element is pointing to the last position
    if(temp->next == NULL){
        InsertAtTail(head,tail,data);
        return;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}
int getvalue(Node* head, int position){
    int count = 1;
    Node*temp = head;
    while(count < position){
        temp = temp->next;
        count++;
    }
    //cout<<"The node at index "<<position<<" is "<<temp->data<<endl;
    int value = temp->data;
    return value;
}
void DeleteNodeAtPos(Node* &head,Node* &tail,int position){
    //when head node is to be deleted
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    // when a middle node or last node is to be deleted
    else{
    int count = 1;
    Node* curr = head;
    Node* prev = NULL;
    while(count < position){
        prev = curr;
        curr = curr->next;
        count++;
    }
    if(curr->next == NULL){
      prev->next = curr->next;
      delete curr;
      //tail->next = prev;
      tail = prev;
    }
    else{
     prev->next = curr->next;
     curr -> next = NULL;
     delete curr;
    }
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
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
     cout<<temp -> data<<" ";
     temp = temp -> next;
    }
    cout<<endl;
}
Node* middle(Node* head){
    int size = length(head)-1;
    int pos;
    Node* middle;
    if(size%2 != 0){
        pos = size/2 + 1;
        middle = getnode(head,pos);
    }
    else{
        pos = (size+1)/2;
        middle = getnode(head,pos);
    }
    return middle;
}
Node* middleOptimised(Node* head){
   // This approach is optimised since it will require linked list travesal for half length once.
    if(head==NULL || head->next == NULL){
        //case1: for empty or 1 element list
        return head;
    }
    else if(head->next->next == NULL){
        //case2: for 2 elements
        return head->next;
    }
    else{
      Node* fast = head->next;
      Node* slow = head;
      while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
          fast= fast->next;
        }
        slow = slow->next;
        }
        return slow;
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    int pos;
    InsertAtHead(head,tail,10);
    InsertAtTail(head,tail,20);
    InsertAtTail(head, tail,30);
    InsertAtTail(head,tail,40);
    InsertAtTail(head,tail,50);
    InsertAtTail(head,tail,60);

    Node* mid = middle(head);
    print(head);
    cout<<"The middle element of the linked list is: "<<endl;
    cout<<mid->data<<endl;
    Node *mid2 = middleOptimised(head);
    cout<<mid2->data<<endl;
    return 0;
}