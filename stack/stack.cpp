#include <iostream>
using namespace std;

class stack_array
{      public:
    // properties
       int* arr;
       int top;
       int size;
    // behavior
    stack_array(){}
    stack_array(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data){
        if(size-top > 1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"Stack overflowed\n";
        }
    }
    void pop(){
        if(top!=-1){
            top--;
        }
        else {
            cout<<"Stack is empty\n";
        }
    }
    int peek(){
        if(top>=0){
          return arr[top];
        }
        else{
            cout<<"stack is empty\n";
            return -1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else return false;
    }
    void print(){
        for(int i=0;i<=top;i++){
          cout<<arr[i]<<" ";
        }cout<<endl;
    }
};
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
class linked_list
{
    public:
    void insert(Node*& head,int data){
        //to insert at head
        Node* temp = new Node(data);
        if(head == NULL){
            head = temp;
            return;
        }
        else{
            temp->next = head;
            head = temp;
            return;
        }
    }
    void deletetop(Node*&head){
        if(head == NULL){
            cout<<"Stack is empty\n";
        }
        else { 
            Node* temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }
    int show(Node*&head){
        return head->data;
    }
    bool check_empty(Node*&head){
        if(head == NULL){
            return true;
        }
        else return false;
    }
    void print(Node* &head){
        if(head == NULL){
            cout<<"Empty stack\n";
            return;
        }
        else{
           Node* temp = head;
           while(temp!=NULL){
               cout<<temp->data<<" ";
               temp = temp->next;
           }
           cout<<endl;
           return;
        }
    }
};
class stack{
    public:
    int data;
    //int size;
    stack* next;
    //stack(){}
    stack(int data){
        this->data = data;
        this->next = NULL;
        //this->size = size;
    }
    ~stack(){
        int val = this->data;
        if(this->next != NULL){
            this->next = NULL;
        }
        cout<<"Stack element with data "<<val<<" removed\n";
    }
};
class stack_ll 
{
    public:
    int size;
    stack_ll(){};
    stack_ll(int size){
        this->size=size;
    }
    void push(stack *&top,int data){
        if(size>0){
          stack* temp = new stack(data);
          if(top == NULL){
            top = temp;
            size--;
           }
           else{
              temp->next = top;
              top = temp;
              size--;
           }
        }
        else{
            cout<<"Stack overflowed\n";
            return;
        }   
    }
    void print(stack*top){
       if(top == NULL){
           cout<<"Stack is empty\n";
           return;
       }
       else{
           stack* temp = top;
           while(temp!=NULL){
               cout<<temp->data<<" ";
               temp = temp->next;
           }cout<<"\n";
       }
    }
    void pop(stack*&top){
        if(top==NULL){
            cout<<"Stack is empty or stack underflow\n";
            return;
        }
        else{
            stack* temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
            size++;
        }
    }
    int peek(stack*&top){
        if(top==NULL){
           cout<<"Stack is empty\n";
           return -1;
        }
        else return top->data;
    }
};
class test : public stack_ll,stack_array
{   public:
    test(){}
    void test_stackArray()
    {
        stack_array s(5);
        s.push(10);
        s.push(15);
        s.push(20);
        cout<<"before pop operation\n";
        s.print();
        //s.peek();
        s.pop();
        cout<<"After pop operation\n";
        s.print();
        //s.peek();
        s.push(30);
        s.push(45);
        s.push(50);
        s.push(12);
        s.push(16);
        s.print();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.print();
    }
    void test_stackLL(){
        //stack* top = new stack(5);
        stack* top = NULL;
        stack_ll s(5);
        s.push(top,10);
        s.push(top,13);
        s.push(top,24);
        s.push(top,30);
        s.push(top,140);
        s.push(top,45);
        s.print(top);
        int p = s.peek(top);
        cout<<p<<"\n";
        s.pop(top);
        s.pop(top);
        s.pop(top);
        s.pop(top);
        s.pop(top);
        s.print(top);
    }
};

int main()
{   
    test t;
    cout<<"Stack implementation using linked list:\n";
    t.test_stackLL();
    cout<<"Stack implementation using array:\n";
    t.test_stackArray();
    return 0;
}
//hehe successful