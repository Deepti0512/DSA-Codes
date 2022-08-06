#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node* next;

   Node(int d){
       this->data = d;
       this->next = NULL;
   }
   ~Node(){
       int value = this->data;
       if(this->next != NULL){
           delete next;
           next = NULL;
       }
       cout<<"Memory is free for node with data "<<value<<endl;
   }
};
int length(Node* tail){
    int count = 0;
    if(tail==NULL){
        return 0;
    }
    else{
        Node* temp = tail;
        do{
            tail = tail->next;
            count++;
        }while(tail != temp);
        return count;
    }
}
void InsertNode(Node* &tail, int element, int data){
   // This function takes as argument the element after which new node is to be inserted and the data of the new node
   // Assumption: the element passed in argument is present in the linked list
   // case 1: Empty Linked List
   if(tail == NULL){
      Node* temp = new Node(data);
      tail = temp;
      temp->next = tail; //since it is circular LL so the first element is pointing to itself. 
    }
    else{
        //non-empty list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;

    }
}
void DeleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout<<"Empty linked list\n";
        return;
    }
    // else if(tail->data == value){
    //     Node* temp = tail;
    //     tail = tail->next->next;
    //     temp->next = NULL;
    //     delete temp;
    // }
    else{
        
        Node* prev = tail;
        Node* curr = prev->next ;
        while(curr->data != value){
            prev = curr;
            curr= curr->next;
        }
        prev->next = curr->next;
        if(tail == curr){
            tail = prev;
        }
        
           
           curr->next = NULL;
           delete curr; 
        
    }
}

void Print(Node* tail){
    Node* temp = tail; //to store tail address
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }
    while(tail != temp);
    cout<<endl;
}

bool detectLoop(Node* head){
    // TC : O(n)
    // SC : O(n)
    
    if(head == NULL){
        return false;
    }
    map<Node*,bool>visited;
    Node* temp = head;
    while(temp != NULL){
        //cycle(loop)present
        if(visited[temp]==true){
            cout<<"Cycle present at element: "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main(){
   Node* tail = NULL;
  // Node* node1 = new Node(10);
  // Node* tail = node1;
   InsertNode(tail,5,2);
   InsertNode(tail,2,4);
   InsertNode(tail,4,5);
   InsertNode(tail,5,6);
   InsertNode(tail,6,7);
   InsertNode(tail,6,7);
   InsertNode(tail,7,1);
  // Print(tail);
//    DeleteNode(tail,7);
//    DeleteNode(tail,4);
//    DeleteNode(tail,6);
//    DeleteNode(tail,2);
//    DeleteNode(tail,5);
//    DeleteNode(tail,1);
//    DeleteNode(tail,7);
   
   //DeleteNode(tail,2);
   Print(tail);
   if(detectLoop(tail)){
       cout<<"cycle is present!\n";
   }
   else cout<<"cycle is not present\n";
   return 0;
}

