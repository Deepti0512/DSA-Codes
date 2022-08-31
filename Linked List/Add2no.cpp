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

class LL_functions
{
public:
    Node *reverse(Node *head)
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

    Node *insert(Node *&head, Node *&tail, int data)
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

    Node *add_logic(Node *&first, Node *&second)
    {
        // Node *anshead = NULL;
        // Node *anstail = NULL;
        // int carry = 0;
        // while (first != NULL || second != NULL || carry != 0)
        // {
        //     int val1 = 0;
        //     if (first != NULL)
        //         val1 = first->data;
        //     int val2 = 0;
        //     if (second != NULL)
        //         val2 = second->data;
        //     int sum = carry + val1 + val2;
        //     int digit = sum % 10;
        //     carry = sum / 10;
        //     insert(anshead, anstail, digit);
        //     if (first != NULL)
        //         first = first->next;
        //     if (second != NULL)
        //         second = second->next;
        // }
        // return anshead;
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

    Node *add(Node *&first, Node *&second)
    {
        // // step1: reverse the lists
        // first = reverse(first);
        // second = reverse(second);

        // // step2: add reversed lists
        // Node *ans = add_logic(first, second);

        // // step3: reverse the result
        // ans = reverse(ans);
        // return ans;

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

    void print(Node *head)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Linked list is empty\n";
            return;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
        return;
    }
};

class Solution
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

int main()
{
    int n1, n2;
    int val1, val2;
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tail1 = NULL;
    Node *tail2 = NULL;
    // LL_functions obj;
    Solution obj;
    cout << "Enter the no.of elements in first linked list: ";
    cin >> n1;
    cout << "Enter the element of first linked list: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> val1;
        obj.insert(head1, tail1, val1);
        // insert(head1, tail1, val1);
    }
    cout << "Enter the no.of elements in second linked list: ";
    cin >> n2;
    cout << "Enter the element of second linked list:";
    for (int i = 0; i < n2; i++)
    {
        cin >> val2;
        obj.insert(head2, tail2, val2);
        // insert(head2, tail2, val2);
    }
    cout << "first linked list: ";
    obj.print(head1);
    cout << "second linked list: ";
    obj.print(head2);
    Node *ans = obj.add(head1, head2);
    Node *sum = obj.add2list(head1, head2);
    cout << "Sum of the two numbers represented by linked list: \n";
    cout << "1)Using recursive function: ";
    obj.print(sum);
    cout << "2)Using normal function: ";
    obj.print(ans);
    /*
    cout<<"test size func:\n";
    int n = obj.size(head1);
    cout<<n<<"\n";
    cout << "first linked list: ";
    obj.print(head1);
    cout << "second linked list: ";
    obj.print(head2);
    cout<<"Test insertAthead function:\n";
    Node* head = NULL;
    obj.insertAtHead(head,10);
    obj.insertAtHead(head,20);
    obj.print(head);
    */
    return 0;
}
