#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

class Linked_List{
    void insertAthead(Node* &head,int data); //1
    void insertAtTail(Node *&head, int data); //2
    void insertAtposition(Node *&head, int pos, int data); //3
    void insertAtIndex(Node *&head, int index, int data);  //4
    int size(Node *head); //5
    void DeleteAtPos(Node *&head, int pos); //6
    void deleteNode(Node *&head, int data); //7
    void print(Node *head); //8
    void getValue(Node* head,int pos); //9
    Node* getNode(Node* &head,int pos); //10
    Node* reverse(Node* &head); //11
};
void Linked_List :: insertAthead(Node* &head,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    head -> prev = newNode;
    newNode->next = head;
    head = newNode;
}
void Linked_List :: insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* tail = head;
    while(tail->next!=NULL){
       tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}