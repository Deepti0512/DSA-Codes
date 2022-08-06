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

Node *solve(Node *&first, Node *&second)
{
    // if only one element is present in first
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }
    // Assign pointers
    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    // loop to traverse both the lists
    while (next1 != NULL && curr2 != NULL)
    {
        // condition to check where element from second list is to be inserted
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // code to insert curr2 between curr1 and next1
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // update pointers
            curr1 = curr1->next;
            curr2 = next2;
        }
        else
        {
            // if the element does lie between curr1 and next1 then update their value and move ahead
            curr1 = curr1->next;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node *mergeSorted(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *ans = NULL;
    // the list with smaller first element is selected as first list
    if (head1->data <= head2->data)
    {
        ans = solve(head1, head2);
    }
    else
    {
        ans = solve(head2, head1);
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

int main()
{
    int n1, n2;
    int val1, val2;
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tail1 = NULL;
    Node *tail2 = NULL;
    cout << "Enter the no.of elements in first linked list: ";
    cin >> n1;
    cout << "Enter the element of first linked list in sorted order: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> val1;
        insertAtTail(head1, tail1, val1);
    }
    cout << "Enter the no.of elements in second linked list: ";
    cin >> n2;
    cout << "Enter the element of second linked list in sorted order:";
    for (int i = 0; i < n2; i++)
    {
        cin >> val2;
        insertAtTail(head2, tail2, val2);
    }
    cout << "Print first linked list: ";
    print(head1);
    cout << "Print first linked list: ";
    print(head2);
    Node *ans = mergeSorted(head1, head2);
    cout << "\nMerged linked list(sorted)\n";
    print(ans);
    cout << "Check location of the two head pointers after merge operation: \n";
    print(head1);
    print(head2);
    cout << "Now let's place the two head pointers at the starting node of merged list \n";
    head1 = ans;
    head2 = ans;
    cout << "Printing head1 and head2...\n";
    print(head1);
    print(head2);
    return 0;
}
//end of program : It's working fine (no errors and no wierd behavior is shown by the code)