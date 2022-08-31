// Love babbar sheet question
#include <bits/stdc++.h>
using namespace std;

class bound
{
public:
    int firstOcc(int arr[], int n, int x)
    {
        int f = -1;
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start) / 2;
        while (start < end)
        {
            if (arr[mid] == x)
            {
                f = mid;
                end = mid - 1;
            }
            else if (arr[mid] > x)
            {
                end = mid - 1;
            }
            else
                start = mid + 1;
            mid = start + (end - start) / 2;
        }
        return f;
    }
    int lastOcc(int arr[], int n, int x)
    {
        int l = -1;
        int low = 0;
        int high = n - 1;
        int middle = low + (high - low) / 2;
        while (low <= high)
        {
            if (arr[middle] == x)
            {
                l = middle;
                low = middle + 1;
            }
            else if (arr[middle] > x)
            {
                high = middle - 1;
            }
            else
                low = middle + 1;
            middle = low + (high - low) / 2;
        }
        return l;
    }
     
    // Recursive Approach
    int first_rec(int arr[], int n,int index, int data){
       //base case
       if(index == n){
           return -1;
       }
       if(arr[index]==data){
           return index;
       }
       else return first_rec(arr,n,index+1,data);
    }
    int last_rec(int arr[], int n, int index, int data){
        //base case
        if(index < 0){
            return -1;
        }
        if(arr[index]==data){
            return index;
        }else return last_rec(arr,n,index-1,data);;
    }
    // All indices of an element in array using recursion
    // return as an array
    vector<int> all_indices(int arr[], int n, int data, int index){
        if(arr[index]==data){
            all_indices(arr,n,data,index+1); 
        }
    }
};
class test : public bound
{   public:
    test()
    {  
        int arr[10] = {1, 3, 4, 4, 4, 4, 4, 4, 4, 5};
        // int f = firstOcc(arr, 10, 4);
        // int l = lastOcc(arr, 10, 4);
        int f = first_rec(arr,10,0,2);
        int l = last_rec(arr,10,9,2);
        //vector<int>all = all_indices(arr,10,0,4,0);
        //int* p = all_indices(arr,10,4,0,0);
        cout << "First occurance of 4 is at index: " << f << endl;
        cout << "Last occurance of 4 is at index: " << l << endl;
        cout<<"All occurences: \n";
        // for(int i = 0; i < 10;i++){
        //     cout<<*(p+i)<<" ";
        // }
        // for(auto val:all){
        //     cout<<val<<" ";
        // }cout<<endl;
        // cout << "The total no.of times 4 occures in given array is: " << l - f + 1 << endl;
    }
};
int main()
{
    test t;
    return 0;
}