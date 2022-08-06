#include<bits/stdc++.h>
#include"SinglyLL.cpp"
using namespace std;

Node* removeDuplicates(Node* &head){
  //TC: O(n)
  // SC: O(1)
  //for sorted linked list
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

//unsorted LL approach 1 (using two loops)
void removeDup_Unsorted1(Node* &head){
    // TC: O(n^2)
    // SC: O(1)
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


//contains errors
Node* removeDup_unsorted2(Node* & head){
    if(head == NULL){
        return NULL;
    }
    map<Node*,bool>visited;
    Node* curr = head;
    
    Node* dup = NULL;
    while(curr!=NULL){
        if(visited[curr] != true){
            visited[curr] = true;
            curr = curr->next;
        }
        else if(visited[curr] == true) {
            //perfrom delete operation
            deleteNode(head,curr);
            // dup = curr->next;
            // curr->data = curr->next->data;
            // curr->next = curr->next->next;
            // delete dup;
            curr = curr->next;
        }
        
    }
    return head;
}

// int main(){
//     return 0;
// }