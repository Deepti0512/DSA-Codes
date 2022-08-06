#include <iostream>
#include <utility> //for using pair
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "The node with value " << val << " is deleted\n";
    }
};

class SLL_functions
{
protected:
    void insertAtHead(Node *&head, int data);               // 1
    void insertAtTail(Node *&head, int data);               // 2
    void insertAtposition(Node *&head, int pos, int data);  // 3
    void insertAtIndex(Node *&head, int index, int data);   // 4
    void insert(Node *&tail, int data);                     // 2.2
    void InsertAtHead2(Node *&head, Node *&tail, int d);    // 2.3
    void InsertAtTail2(Node *&head, Node *&tail, int data); // 2.4
    int size(Node *head);                                   // 5
    void DeleteAtPos(Node *&head, int pos);                 // 6
    void deleteNode(Node *&head, int data);                 // 7
    void print(Node *head);                                 // 8
    void getValue(Node *head, int pos);                     // 9
    Node *getNode(Node *&head, int pos);                    // 10
    Node *reverse(Node *&head);                             // 11.1
    Node *reverseRecursive(Node *head);                     // 11.2
    Node *getmiddle(Node *&head);                           // 12.1
    std::pair<int, Node *> middle(Node *head);              // 12.2
    Node *reverseIn_Kgrp(Node *&head, int k);               // 13
    bool isCircular(Node *&head);                           // 14.1
    bool isCircularUsingMap(Node *&head);                   // 14.2
    /*class detect_n_remove_Loop                            // 15
    {
    //nested class ka fayeda nhi hua kyunki isme base class ke functions ka access nhi h.🥲
    public:
        bool detectLoop(Node *&head)
        {
            if (head == NULL)
            {
                cout << "List is empty\n";
                return true;
            }
            map<Node *, int> visited;
            Node *temp = head;
            while (temp->next != NULL)
            {
                if (visited[temp] == 1)
                {
                    return true;
                }
                else
                {
                    visited[temp] = 1;
                    temp = temp->next;
                }
            }
            return false;
        }
    };
    */
    void removeDuplicates_sorted(Node *&head);
    void removeDuplicates_unsorted(Node *&head);
    void sort012_m1(Node *&head);
    Node *sort012_m2(Node *&head);
    // Node *Add_Recursive(Node *&first, Node *&second);
    // Node *Add_help(Node *&first, Node *&second, int p1, int p2, int carry);
    // Node *Add2lists(Node *&first, Node *&second);
    // Node *Add(Node *&first, Node *&second);
    // Node *getMid(Node *&head);
    // Node *merge2Sorted_list(Node *&left, Node *&right);
    // Node *mergeSort(Node *&head);
};

void SLL_functions ::insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void SLL_functions ::insertAtTail(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = temp;
    }
}
void SLL_functions ::insertAtposition(Node *&head, int pos, int data)
{
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, data);
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
}
void SLL_functions ::insertAtIndex(Node *&head, int index, int data)
{
    if (index == 0)
    {
        insertAtHead(head, data);
        return;
    }
    int count = 0;
    Node *temp = head;
    while (count < index - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, data);
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
}
void SLL_functions ::insert(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}
int SLL_functions ::size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void SLL_functions ::DeleteAtPos(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    if (pos < 1 || pos > size(head))
    {
        cout << "Invalid position\n";
        cout << "List size is " << size(head) << ".\nEnter position accordingly\n";
        return;
    }
    if (pos == 1)
    {
        Node *temp = head->next;
        Node *del = head;
        head = temp;
        delete del;
        return;
    }
    Node *prev = NULL;
    Node *curr = head;
    int count = 1;
    while (count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
void SLL_functions ::deleteNode(Node *&head, int data)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->data == data)
    {
        Node *a = head;
        head = head->next;
        delete a;
        return;
    }
    Node *prev = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}
void SLL_functions ::print(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void SLL_functions ::getValue(Node *head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < pos)
    {
        temp = temp->next;
        count++;
    }
    cout << "The value at position " << pos << " (or index " << pos - 1 << ") is: " << temp->data << endl;
    return;
}
Node *SLL_functions ::getNode(Node *&head, int pos)
{
    if (pos == 1)
    {
        return head;
    }
    if (pos < 1 || pos > size(head))
    {
        cout << "Invalid position\nNode doesn't exist!\n";
        return NULL;
    }
    Node *temp = head;
    int count = 1;
    while (count < pos)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}
Node *SLL_functions ::reverse(Node *&head)
{
    // this function  changes the actual linkedlist
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return prev;
}
Node *SLL_functions::reverseRecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *chhotahead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return chhotahead;
}
Node *SLL_functions ::getmiddle(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
std::pair<int, Node *> SLL_functions ::middle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return std::make_pair(1, head);
    }
    Node *slow = head;
    Node *fast = head->next;
    int count = 1;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }
    return std::make_pair(count, slow);
}
Node *SLL_functions ::reverseIn_Kgrp(Node *&head, int k)
{
    if (head == NULL)
    {
        // if no element or one element is present
        return head;
    }
    // step1: reverse k nodes from starting
    int count = 0;
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = curr->next;
    while (count < k && curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // use recursion for reversing the rest of the nodes in groups of k
    if (forward != NULL)
    {
        head->next = reverseIn_Kgrp(forward, k);
    }
    // prev is now pointing to the head of reversed list
    head = prev;
    return prev;
}
bool SLL_functions ::isCircular(Node *&head)
{
    if (head == NULL)
    {
        return true;
    }
    Node *temp = head;
    while (temp->next != head && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        return false;
    }
    else
        return true;
}
bool SLL_functions ::isCircularUsingMap(Node *&head)
{
    if (head == NULL)
    {
        return true;
        // returning true if no element is present
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        else
        {
            visited[temp] = true;
            temp = temp->next;
        }
    }
    return false;
}
void SLL_functions ::removeDuplicates_sorted(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *curr = head;
    // Node* frwd = curr->next;
    while (curr->next != NULL)
    {
        Node *frwd = curr->next;
        if (curr->data == frwd->data)
        {
            curr->next = frwd->next;
            frwd->next = NULL;
            delete frwd;
        }
        else
        {
            curr = curr->next;
        }
    }
    return;
}
void SLL_functions ::removeDuplicates_unsorted(Node *&head)
{
    // method 1 : sort the list and then remove duplicates but how we sort a linked list?
    // method 2 : using map
    /*
       Node* prev = head;
       Node* curr = head;
       while(curr->next!=NULL){
          Node* temp1 = curr;
          curr = curr->next;
          prev = temp1;
          cout<<"prev->data: "<<prev->data<<" "<<"curr->data: "<<curr->data<<endl;
    }
    */
    map<int, int> visited;
    Node *curr = head;
    Node *prev = NULL;
    visited[head->data] = 1;
    while (curr->next != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        prev = temp;
        if (visited[curr->data] == 1)
        {
            // code for delete
            Node *todel = curr;
            curr = prev;
            prev->next = todel->next;
            todel->next = NULL;
            delete todel;
        }
        else
        {
            visited[curr->data] = 1;
        }
    }
}
void SLL_functions ::sort012_m1(Node *&head)
{
    // method 1: count 0's, 1's and 2's and then put values accordingly
    Node *temp = head;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
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
    while (temp != NULL)
    {
        while (count0 != 0)
        {
            temp->data = 0;
            count0--;
            temp = temp->next;
        }
        while (count1 != 0)
        {
            temp->data = 1;
            count1--;
            temp = temp->next;
        }
        while (count2 != 0)
        {
            temp->data = 2;
            count2--;
            temp = temp->next;
        }
    }
}
Node *SLL_functions ::sort012_m2(Node *&head)
{
    // method 2 : make three linked lists for storing 0s, 1s and 2s
    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;
    Node *onehead = new Node(-1);
    Node *onetail = onehead;
    Node *twohead = new Node(-1);
    Node *twotail = twohead;
    Node *temp = head;
    // Step 1: make three lists
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            insert(zerotail, 0);
        }
        else if (temp->data == 1)
        {
            insert(onetail, 1);
        }
        else
            insert(twotail, 2);
        temp = temp->next;
    }
    // step 2: merge the three lists
    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
        onetail->next = twohead->next;
    }
    else
    {
        zerotail->next = twotail->next;
    }
    twotail->next = NULL;
    // set up new head
    head = zerohead->next;
    // delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

    return zerohead;
}
void SLL_functions ::InsertAtHead2(Node *&head, Node *&tail, int d)
{
    // in case of empty linked list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}
void SLL_functions ::InsertAtTail2(Node *&head, Node *&tail, int data)
{
    // in case of empty list
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

class Add
{
public:
    void insert(Node *&head, Node *&tail, int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    Node *reverse(Node *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        else
        {
            Node *prev = NULL;
            Node *curr = head;
            Node *frwd = curr->next;
            while (curr != NULL)
            {
                frwd = curr->next;
                curr->next = prev;
                prev = curr;
                curr = frwd;
            }
            // head = prev;
            return prev;
        }
    }

    Node *add(Node *&fi, Node *&se)
    {
        Node *first = fi;
        Node *second = se;
        int carry = 0;
        Node *anshead = NULL;
        Node *anstail = NULL;
        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if (first != NULL)
                val1 = first->data;

            int val2 = 0;
            if (second != NULL)
                val2 = second->data;

            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            insert(anshead, anstail, digit);
            if (first != NULL)
                first = first->next;
            if (second != NULL)
                second = second->next;
        }
        return anshead;
    }

    // Function to add two numbers represented by linked list.
    Node *addTwoLists(Node *&first, Node *&second)
    {
        // step1 : reverse both the lists
        first = reverse(first);
        second = reverse(second);

        // step2 : add them
        Node *ans = add(first, second);

        // step 3: reverse again
        // first = reverse(first);
        // second = reverse(second);
        ans = reverse(ans);

        return ans;
    }

    void insertAtHead(Node *&head, int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        return;
    }

    int size(Node *&head)
    {
        Node *temp = head;
        int s = 0;
        while (temp != NULL)
        {
            s++;
            temp = temp->next;
        }
        return s;
    }

    int addRecursive(Node *&first, int pv1, Node *&second, int pv2, Node *&ans)
    {
        if (first == NULL && second == NULL)
        {
            return 0; // carry will be zero in this case
        }
        int data = 0;
        if (pv1 > pv2)
        {
            int oc = addRecursive(first->next, pv1 - 1, second, pv2, ans);
            data = first->data + oc;
        }
        else if (pv2 > pv1)
        {
            int oc = addRecursive(first, pv1, second->next, pv2 - 1, ans);
            data = second->data + oc;
        }
        else
        {
            int oc = addRecursive(first->next, pv1 - 1, second->next, pv2 - 1, ans);
            data = first->data + second->data + oc;
        }
        int d = data % 10;  // digit to be inserted in resultant linked list
        int nc = data / 10; // new carry
        insertAtHead(ans, d);
        return nc;
    }
    Node *add2list(Node *&fi, Node *&se)
    {
        Node *first = fi;
        Node *second = se;
        Node *ans = NULL; // head of resulatant linked list which will store sum
        int f = size(first);
        int s = size(second);
        int oc = addRecursive(first, f, second, s, ans);
        if (oc > 0)
        {
            insertAtHead(ans, oc);
        }
        return ans;
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
};

class detect_n_remove_Loop : public SLL_functions
{
    // this class contains 4 functions related to detection and removal of loop in a linked list
public:
    bool detectLoop(Node *&head)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return true;
        }
        map<Node *, int> visited;
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (visited[temp] == 1)
            {
                return true;
            }
            else
            {
                visited[temp] = 1;
                temp = temp->next;
            }
        }
        return false;
    }
    Node *FloydsAlgoDetectLoop(Node *&head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *slow = head;
        Node *fast = head;
        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            if (slow == fast)
            {
                return slow; // point of intersection returned
            }
        }
        return NULL;
    }
    Node *startingNode(Node *&head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *slow = head;
        Node *intersection = FloydsAlgoDetectLoop(head);
        if (intersection == NULL)
        {
            return NULL;
        }
        while (slow != intersection)
        {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
    void removeLoop(Node *&head)
    {
        Node *start = startingNode(head);
        if (start == NULL)
        {
            return;
        }
        Node *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
    bool floyd(Node *&head)
    {
        if (head == NULL)
        {
            cout << "empty list\n";
            return false;
        }
        Node *slow = head;
        Node *fast = head;
        while (slow != fast && (fast != NULL || fast->next != NULL))
        {
            slow = slow->next;
            fast = fast->next;
        }
        if (slow == fast)
        {
            cout << "Loop detected\n";
            return true;
        }
        else
        {
            cout << "Loop is not present\n";
            return false;
        }
    }
};

class test : public SLL_functions
{
public:
    test()
    {
        // cout << "Hello\n";
    }
    void Test(void)
    {   /*
        Node *head = NULL;
        insertAtHead(head, 100);
        insertAtTail(head, 200);
        insertAtIndex(head, 0, 50);
        insertAtposition(head, 3, 150);
        insertAtposition(head, 5, 250);
        insertAtIndex(head, 5, 300);
        print(head);
        Node *head2 = NULL;
        cout << size(head2) << " " << size(head) << endl;
        /* Delete operations:
           DeleteAtPos(head, 1);
           DeleteAtPos(head,3);
           DeleteAtPos(head,4);
           deleteNode(head,150);
           deleteNode(head, 100);
           deleteNode(head, 300);
           print(head);
        */
        /*
        getValue(head, 2);
        getValue(head2, 1);
        Node *n = getNode(head, 6);
        if (n != NULL){
            cout << n->data << endl;
        }
        Node *rev = reverse(head);
        print(rev);
        print(head);
        Node *rev2 = reverseRecursive(head);
        print(rev2);
        head = rev2;
        pair<int, Node *> mid = middle(head);
        cout << "Middle node is at position " << mid.first << " and it's value is: " << mid.second->data << endl;
        Node *mid1 = getmiddle(head);
        cout << "mid->data " << mid1->data << endl;
        Node *ans = reverseIn_Kgrp(head, 6);
        print(ans);
        // let's make the linked list circular
        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = head;
        cout << isCircular(head) << endl;
        cout << isCircularUsingMap(head) << endl;
        detect_n_remove_Loop obj;
        cout << obj.detectLoop(head) << endl;
        obj.floyd(head);
        cout << "Starting node of the loop: " << obj.startingNode(head)->data << endl;
        cout << "let's remove the loop\n";
        obj.removeLoop(head);
        print(head);
        Node* head3 = NULL;
        for(int i=1;i<6;i++){
            insertAtTail(head3,i);
        }
        insertAtposition(head3,1,1);
        insertAtposition(head3,3,2);
        insertAtposition(head3,6,4);
        insertAtTail(head3,5);
        print(head3);
        removeDuplicates_sorted(head3);
        print(head3);
        Node* temp = NULL;
        insertAtTail(temp,1);
        insertAtTail(temp,2);
        insertAtTail(temp,2);
        insertAtTail(temp,3);
        insertAtTail(temp,4);
        removeDuplicates_sorted(temp);
        print(temp);
        Node* hey = NULL;
        insertAtTail(hey,1);
        insertAtTail(hey,2);
        insertAtTail(hey,1);
        insertAtTail(hey,4);
        insertAtTail(hey,3);
        insertAtTail(hey,5);
        insertAtTail(hey,2);
        insertAtTail(hey,3);
        print(hey);
        removeDuplicates_unsorted(hey);
        print(hey);
        Node *hello = new Node(1);
        insertAtHead(hello, 1);
        insertAtHead(hello, 1);
        insertAtHead(hello, 1);
        print(hello);
        removeDuplicates_unsorted(hello);
        print(hello);
        Node *hehe = new Node(1);
        insertAtHead(hehe, 2);
        insertAtHead(hehe, 0);
        insertAtHead(hehe, 1);
        insertAtHead(hehe, 1);
        insertAtHead(hehe, 0);
        insertAtHead(hehe, 2);
        print(hehe);
        sort012_m2(hehe);
        print(hehe);
        */ 
        Node *list1 = NULL;
        Node *list2 = NULL;
        insertAtHead(list1, 9);
        insertAtHead(list1, 8);
        insertAtHead(list1, 6);
        insertAtHead(list2, 2);
        insertAtHead(list2, 6);
        //Node *res = Add2lists(list1, list2);
        //print(res);
    }
};

int main()
{
    test t;
    t.Test();
    return 0;
}
