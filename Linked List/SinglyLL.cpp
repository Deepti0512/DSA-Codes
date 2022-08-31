#include<iostream>
#include<map>
//#include"duplicates_sortedLL.cpp"
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
       int value = this -> data;
       if(this->next != NULL){
           this->next = NULL;
           delete next;
       }
       cout<<value<<" is deleted from the Linked list\n";
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
void getvalue(Node* head, int position){
    int count = 1;
    Node*temp = head;
    while(count < position){
        temp = temp->next;
        count++;
    }
    cout<<"The node at index "<<position<<" is "<<temp->data<<endl;
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
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
     cout<<temp -> data<<" ";
     temp = temp -> next;
    }
    cout<<endl;
}
bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    map<Node*,bool>visited;
    Node* temp = head;
    while(temp != NULL){
        //cycle(loop)present
        if(visited[temp]==true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node* removeDuplicates(Node* &head){
  if(head == NULL){
    return NULL;
  }
  Node* curr = head;
  while(curr!=NULL){
    if(( curr->next != NULL) && curr->data == curr->next->data){
        Node* temp = curr->next;
        Node* newNode = curr->next->next;
        temp->next = NULL;
        delete temp;
        curr->next = newNode;
    }
    else{
        curr = curr->next;
    }
  }
  
  return head;
}

void removeDup_Unsorted1(Node* &head){
    if(head == NULL)
    return;
    Node* curr = head;
    Node* temp = curr;
    Node* dup = NULL;
    while(curr!=NULL && curr->next != NULL){
        temp = curr;
        while(temp->next!=NULL){
            if(curr->data == temp->next->data){
                //perform delete operation
                dup = temp->next;
                temp->next = temp->next->next;
                delete dup;
            }
        else temp = temp->next;
        }
        curr = curr->next;
    }
    return;
}

Node* deleteNode(Node* &head, Node* &curr){
    Node* temp = head;
    while(temp->next!=curr){
        temp = temp->next;
    }
    Node* dup = temp->next;
    temp->next = temp->next->next;
    dup->next = NULL;
    delete dup;
    return temp;
}

int main(){
Node* node1 = new Node(1);
Node* head = node1;
Node* tail = node1;
/*  cout<< node1 -> data<<endl;
  cout<< node1 -> next<<endl;
  Node* head = node1; //node1 is the head pointer now
  Node* tail = node1;
  InsertAtHead(head,tail,12);
  //print(head);
  InsertAtHead(head,tail,15);
  InsertAtTail(head,tail,100);
  InsertAtPosition(head, tail, 6, 60);
  InsertAtPosition(head,tail,1,55);
  InsertAtPosition(head,tail,5, 120);
  //print(head);
  cout<<"Length of Linked list : "<<length(head)<<endl;
  cout<<"Enter the number of elements to be inserted in Linked list: ";
  int size;
  cin>>size;
  for(int i = 0; i<size; i++){
     InsertAtTail(head,tail,i);
  }
 
  getvalue(head,2);
  //print(head);
  cout<<"head: "<<head->data<<" tail: "<<tail->data<<endl;
  // tail->next = head->next->next; 
 //  if(detectLoop(head)){
 //     cout<<"Cycle is present!"<<endl;
 //  }
 //  else cout<<"Cycle is not present!"<<endl;

  //InsertAtTail(head,tail,3);
*/
InsertAtTail(head,tail,2);
InsertAtTail(head,tail,2);
InsertAtTail(head,tail,2);
InsertAtTail(head,tail,3);
InsertAtTail(head,tail,3);
InsertAtTail(head,tail,4);
InsertAtTail(head,tail,5);
InsertAtTail(head,tail,6);
InsertAtTail(head,tail,6);
InsertAtTail(head,tail,7);
InsertAtTail(head,tail,7);
InsertAtTail(head,tail,8);
print(head);
removeDuplicates(head);
print(head);

Node* node2 = new Node(5);
Node* head2 = node2;
Node* tail2 = node2;
InsertAtTail(head2,tail2,4);
InsertAtTail(head2,tail2,4);
InsertAtTail(head2,tail2,3);
InsertAtTail(head2,tail2,1);
InsertAtTail(head2,tail2,5);
InsertAtTail(head2,tail2,6);
InsertAtTail(head2,tail2,4);
InsertAtTail(head2,tail2,7);
InsertAtTail(head2,tail2,2);
print(head2);
//Node* ans = removeDup_unsorted2(head2);
//print(ans);
// Node* curr = head2;
// deleteNode(head2,head2->next->next);
// print(head2);
return 0;
}