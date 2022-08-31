#include<iostream>
#include<set>
using namespace std;
  
/* SET: stores only distinct values
   returns elements in sorted order
   elements once pushed cannot be modified
   only insertion and deletion can be done
   unordered set : faster & returns elements in random order
*/

//One of the many applications of set
void distinct(int arr[],int n){
    set<int>s;
    for(int i=0; i<n ;i++){
        s.insert(arr[i]);
    }
    for(auto val:s){
        cout<<val<<" ";
    }cout<<endl;
}
int main(){
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(1);
    s.insert(3);
    s.insert(1);
    s.insert(3);

    for(auto val:s){
        cout<<val<<" ";
    }cout<<endl;

    set<int>::iterator it = s.begin();
    it++;
   // s.erase(it);

    // for(auto val:s){
    //     cout<<val<<" ";
    // }cout<<endl;
    
   //count function to check if given element is present or not
   cout<<"Is 5 present -> "<<s.count(5)<<endl;
   cout<<"Is 1 present -> "<<s.count(1)<<endl;
   
   // find function returns the iterator(pointer) at which given element is present
   set<int>::iterator itr = s.find(2);
   cout<<"Element present at itr -> "<<*itr<<endl;
   for(auto it = itr ; it!= s.end(); it++){
       cout<<*it<<" ";
   }cout<<endl;
    int arr[] ={1,4,2,2,3,4,1,5,6,5,6,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given array: \n";
    for(int i:arr){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"Printing distinct elements of given array using set:"<<endl;
    distinct(arr,n);
    // Time complexity of insert , count , erase and find is O(logn)
    // Time complexity of size, begin, end, empty is O(1)

   return 0;
}
