// Problem Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/

/* Approach :
1) Find the maximum element TC: O(n)
2) use binary search O(logn)
*/
#include<iostream>
using namespace std;

int solve(int arr[],int n){
    int start = 0;
    int end = n - 1;
    int mid = start + (end-start)/2;
    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int main(){
    return 0;
}