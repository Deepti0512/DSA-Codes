#include<bits/stdc++.h>
#include"CircularSinglyLL.cpp"
using namespace std;
//time complexity:  O(n)
// space complexity : O(1)
bool IsCircular(Node* head){
    if(head == NULL){
        return true;
    }
    //more than one element
    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    else if(temp == NULL){
        return false;
    }
}

// int main(){
//    Node* tail = NULL;
//   // Node* node1 = new Node(10);
//   // Node* tail = node1;
//    InsertNode(tail,5,2);
//    InsertNode(tail,2,4);
//    InsertNode(tail,4,5);
//    InsertNode(tail,5,6);
//    InsertNode(tail,6,7);
//    InsertNode(tail,6,7);
//    InsertNode(tail,7,1);
//   // Print(tail);
//    bool flag = IsCircular(tail);
//    if(flag){
//        cout<<"Yes\n";
//    }
//    else cout<<"No"<<endl;
   
//    return 0;
// }


