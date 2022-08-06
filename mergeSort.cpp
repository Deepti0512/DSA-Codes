#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node*&head,Node*&tail, int d){
    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        tail->next = newNode;
        tail = newNode;
        return;
    }
}

void print(Node*head){
    Node* temp = head;
    if(head == NULL){
        cout<<"Empty list\n";
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp ->next;
    }cout<<endl;
}

Node *getMid(Node *&head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *merge2Sorted_list(Node *&left, Node *&right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    Node *ans = new Node(-1);
    Node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
Node* merge(Node* head1 , Node* head2)
   {
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node* ans = NULL;
    if(head1->data <= head2->data)
    {
        ans = head1;
       ans->next = merge(head1->next ,head2);
    }
    else
    {
        ans=head2;
        ans->next = merge(head1 ,head2->next);
    }
    return ans;
}
Node *mergeSort(Node *&head){
    // base case
    if (head == NULL || head->next == NULL){
        return head;
    }
    // divide the list in two halves
    Node *mid = getMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    // cout<<"left: ";
    // print(left);
    // cout<<"right: ";
    // print(right);
    // Recursive calls
    left = mergeSort(left);
    right = mergeSort(right);

    // merge the two lists
     
    Node* result = merge2Sorted_list(left, right);
    return result;
}
/* correct solution 
Node* merge(Node* head1 , Node* head2)
   {
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node* ans = NULL;
    if(head1->data <= head2->data)
    {
        ans = head1;
       ans->next = merge(head1->next ,head2);
    }
    else
    {
        ans=head2;
        ans->next = merge(head1 ,head2->next);
    }
    return ans;
}

   Node* mergeSort(Node* head) {
       // your code here
       if(head==NULL || head->next==NULL)
       return head;
       Node *slow=head,*fast=head,*temp=NULL;

       while(fast!=NULL && fast->next!=NULL){
           temp=slow;
           slow=slow->next;
           fast=fast->next->next;
       }

       temp->next=NULL;
       Node *left=mergeSort(head);
       Node *mid=mergeSort(slow);
       Node *res=merge(left,mid);
       return res;
   }
*/
int main()
{   
    Node* head = NULL;
    Node* tail = NULL;
    insert(head,tail,5);
    insert(head,tail,2);
    insert(head,tail,3);
    insert(head,tail,1);
    print(head);
    mergeSort(head);
    print(head);
    return 0;
}