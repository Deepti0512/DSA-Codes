#include<bits/stdc++.h>
using namespace std;

/* Objective: To print the element occuring more than once in the given array
   Approach(1):
  i) Sort the Array
  ii) traverse the array checking ith and (i+1)th value 
  iii) if the two values comes out to be same then print it
  iv) To handle the case of more than 2 occuurences of an element, keep a record of the element which has been printed already
  Note: This approach is useful where the range of array is not defined and can exceed a large value due to which creating hash maps is not feasible
  Caution: Note that by using this approach the output will be in sorted order not in the order in which they are present in the given array
*/

void printDuplicates(int arr[],int n){
  sort(arr,arr+n); //STL function
    int lastDuplicate = 0;
    for(int i = 0; i < n; i++){
      if(arr[i]==arr[i+1] && arr[i] != lastDuplicate){
        cout<<arr[i]<<" ";
        lastDuplicate = arr[i];
      }
    }
    cout<<endl;
}
/* Approach 2: time complexity: O(n) ; space complexity: O(1)
will do it later as i am too exhausted rn
*/
//Counting the occurrences of elements i.e frequency of duplicates elements
void countDuplicates(int arr[], int n){
   sort(arr,arr+n);
   for(int i = 0; i<n-1;i++){
       if(arr[i]==arr[i+1]){
           int j = i+1;
           while(arr[j]==arr[i])j++;
           cout<<arr[i]<<" is present "<<j-i<<" times."<<endl;
           i = j-1;
       }
   }
}
int main(){
    int n;
    cout<<"Enter the size of array: \n";
    cin>>n;
    int * arr = new int[n];
    cout<<"Enter array elements: \n";
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    printDuplicates(arr,n);
    countDuplicates(arr,n);
    return 0;
}



