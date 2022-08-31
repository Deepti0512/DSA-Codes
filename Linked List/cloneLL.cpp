#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};
class Clone_list
{
public:
    void insert(Node *&head, Node *&tail, int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    Node *clone(Node *head)
    {
        // tc:o(n)
        // sc: o(n)
        Node *temp = head;
        Node *anshead = NULL;
        Node *anstail = NULL;
        map<Node *, Node *> mapping;
        // step1 : create a clone list
        while (temp != NULL)
        {
            insert(anshead, anstail, temp->data);
            // mapping[temp]=anstail;
            // cout<<"mapping[temp]->data: "<<mapping[temp]->data<<" ";
            temp = temp->next;
        }
        cout << endl;
        // Step2: create a map
        temp = head;
        Node *temp2 = anshead;
        while (temp != NULL)
        {
            mapping[temp] = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
        // Step3 : assign random pointers to clone list using mapping
        temp = head;
        temp2 = anshead;
        while (temp != NULL)
        {
            temp2->random = mapping[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return anshead;
    }
    Node *clone_approach2(Node *&head)
    {
        /*..Approach : instead of making a map for storing mapping directly map the two lists using next pointers
           and then after assigning the random pointers in the clone list, get back the two lists */
        // Time complexity : O(n), Space complexity : O(1)
        // Step 1: make a clone list with next pointers
        Node *temp = head;
        Node *anshead = NULL;
        Node *anstail = NULL;
        while (temp != NULL)
        {
            insert(anshead, anstail, temp->data);
            temp = temp->next;
        }
        // connect using next pointers
        temp = head;
        Node *temp2 = anshead;
        while (temp != NULL)
        {
            Node *save = temp->next;
            temp->next = temp2;
            temp = save;
            Node *save2 = temp2->next;
            temp2->next = temp;
            temp2 = save2;
        }
        // print2(head);
        // step3: assign random pointers
        temp = head;
        temp2 = anshead;
        while (temp != NULL)
        {
            if (temp->next != NULL)
            {
                temp->next->random = temp->random ? temp->random->next : NULL;
            }
            temp = temp->next->next;
        }
        // print2(head);
        // step3 : get back the original lists
        temp = head;
        temp2 = anshead;
        while (temp != NULL && temp2 != NULL)
        {
            temp->next = temp2->next;
            temp = temp->next;
            if (temp != NULL)
            {
                temp2->next = temp->next;
            }
            temp2 = temp2->next;
        }

        // step4: return answer
        return anshead;
    }
    void Assign_random_ptrs(Node *&head, Node *&tail)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp->random = head->next->next;
            temp = temp->next;
            temp->random = head;
            temp = temp->next;
            temp->random = tail;
            temp = temp->next;
            temp->random = head->next->next;
            temp = temp->next;
            temp->random = head->next;
        }
    }
    void print(Node *head)
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "temp->data: " << temp->data << " "
                 << " temp->random->data: " << temp->random->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    void print2(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class test : public Clone_list
{
public:
    test()
    {
        Node *head = NULL;
        Node *tail = NULL;
        for (int i = 1; i < 6; i++)
        {
            insert(head, tail, i);
        }
        Assign_random_ptrs(head, tail);
        cout << "Given linked list: \n";
        print(head);
        Node *ans = clone(head);
        cout << "Clone 1 (using mapping method):\n";
        print(ans);
        print2(ans);
        Node *res = clone_approach2(head);
        cout << "Clone 2 (without using extra space)\n";
        print2(res);
        print(res);
    }
};

int main()
{
    test t;
    return 0;
}
