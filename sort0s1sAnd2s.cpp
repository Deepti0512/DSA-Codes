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
    // ~Node(){
    //     int val = this->data;
    //     if(this->next!=NULL){
    //         this->next = NULL;
    //     }
    //     cout<<"Element with value "<<val<<" is deleted from the linked list.\n";
    // }
};

// Approach 1
Node *sort1(Node *&head)
{
    // TC: O(n)
    // SC: O(1)
    if (head == NULL)
    {
        return NULL;
    }
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            count0++;
        }
        else if (temp->data == 1)
        {
            count1++;
        }
        else
            count2++;
        temp = temp->next;
    }
    temp = head;
    while (count0 != 0)
    {
        temp->data = 0;
        temp = temp->next;
        count0--;
    }
    while (count1 != 0)
    {
        temp->data = 1;
        temp = temp->next;
        count1--;
    }
    while (count2 != 0)
    {
        temp->data = 2;
        temp = temp->next;
        count2--;
    }
    return head;
}

void insert(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

// Approach 2
Node *sort2(Node *&head)
{
    // TC: O(n);
    // SC: o(1);
    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;
    Node *onehead = new Node(-1);
    Node *onetail = onehead;
    Node *twohead = new Node(-1);
    Node *twotail = twohead;

    Node *curr = head;

    // create seperate lists for 0s, 1s and 2s
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            insert(zerotail, curr);
        }
        else if (curr->data == 1)
        {
            insert(onetail, curr);
        }
        else if (curr->data == 2)
        {
            insert(twotail, curr);
        }
        curr = curr->next;
    }

    // merge the three lists

    // if 1's list is not empty
    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
        onetail->next = twohead->next;
    }
    else if (onehead->next == NULL)
    {
        zerotail->next = twohead->next;
    }
    twotail->next = NULL;

    // setup head
    head = zerohead->next;

    // delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "list is empty!\n";
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n, val;
    cout << "Enter the no.of elements to be inserted:\n";
    cin >> n;
    cout << "Enter elements of the list (only 0,1 or 2): \n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertAtTail(head, tail, val);
    }
    cout << "Linked list before sorting 0s, 1s and 2s: \n";
    print(head);
    // sort1(head);
    sort2(head);
    cout << "Sorted Linked list\n";
    print(head);
    return 0;
}
// Both functions are working fine... Hurray!!