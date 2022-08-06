#include <bits/stdc++.h>
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

class solution
{
private:
    bool check(vector<int> arr)
    {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            if (arr[s] != arr[e])
            {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    Node *getMId(Node *&head)
    {
        Node *slow = head;
        Node *fast = head->next;
        //this logic returns left wala middle node for even no.of elements
        //if we take slow = head and fast = head then right wala middle is returned in even case
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node *reverse(Node *&head)
    {
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
        return prev;
    }

public:
    // Approach 1
    bool check_palindrome1(Node *&head)
    { // TC: O(n)
        // SC: O(n)

        // Approach: COPY data in an array and then check if palindrome
        vector<int> v;
        Node *temp = head;
        while (temp != NULL)
        {
            v.push_back(temp->data);
            temp = temp->next;
        }
        return check(v);
    }
    bool check_palindrome2(Node *&head)
    {
        // TC: O(N)
        // SC: O(1)
        if (head->next == NULL)
        {
            return true;
        }
        // step1: find middle
        Node *middle = getMId(head);

        // Step 2: reverse the second half
        Node *temp = middle->next;
        middle->next = reverse(temp);

        // Step 3: compare both halves
        Node *head1 = head;
        Node *head2 = middle->next;

        while (head2 != NULL)
        {
            if (head1->data != head2->data)
            {   /* step 4: repeat step 2 to get back the original linked list
                we need to write the following two statements here because if it is not palindrome then the function will exit from here with a false value without updating the linked list */
                temp = middle->next;
                middle->next = reverse(temp);
                // if the data is not equal then return
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        // step 4: repeat step 2 to get back the original linked list
        temp = middle->next;
        middle->next = reverse(temp);
        return true;
    }
};

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
    cout << "Enter the no.of elements in linked list: ";
    cin >> n;
    cout << "Enter the element of linked list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertAtTail(head, tail, val);
    }
    cout << "LL: ";
    print(head);
    solution obj;
    bool flag = obj.check_palindrome2(head);
    if (flag)
    {
        cout << "Given linked list is a palindrome! \n";
    }
    else
    {
        cout << "Not a palindrome!\n";
    }
    cout << "LL: ";
    print(head);
    return 0;
}