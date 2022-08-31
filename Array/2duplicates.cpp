#include<bits/stdc++.h>
using namespace std;

/* You are given an array of n+2 elements. All elements of the array are in range 1 to n. 
And all elements occur once except two numbers which occur twice. Find the two repeating numbers (refer gfg).
Eg: Input: {1,2,3,2,4,5,4} , n=5
Expected output: 2,4
*/

int fact(int n){
    return (n==0)?1:n*fact(n-1);
}

void duplicates(int arr[], int size){
    //Approach: finding the two numbers using equations
    int s=0;
    int p=1;
    int x,y;
    int d;
    int n = size -2;
    for(int i=0;i<size;i++){
        s = s + arr[i];
        p = p*arr[i];
    }
    //cout<<"s: "<<s<<" p: "<<p<<endl;
    s = s - n*(n+1)/2; //s becomes x+y
    p = p/fact(n);         //p becomes xy
    d = sqrt(s*s - 4*p); // d becomes x-y
    //cout<<"s: "<<s<<" p: "<<p<<" d:"<<d<<endl;
    x = (d+s)/2;
    y = (s-d)/2;
    cout<<"The two repeating numbers are "<<x<<" and "<<y<<endl;

    /* Time Complexity: O(n) 
    Space Complexity: O(1)*/
}

/* Approach 2: using xor operation 
will try this approach later as I haven't learned bit manipulation yet
*/

int main(){
    int size;
    cout<<"Enter the size of array: \n";
    cin>>size;
    int arr[size];
    cout<<"Enter array elements: \n";
    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }
    duplicates(arr,size);
    return 0;
}