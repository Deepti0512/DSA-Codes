#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void solve(int arr[],int n){
    //Two pointer approach (ye maine khud sochi thi fir gfg se thodi si help lekr implement krdi)
    //TC: O(n) & SC: O(1)
    int i = 0;
    int j = n-1;
    while(i<=j){
      if(arr[i]<0 && arr[j]<0){
            i++;
        }  
      else if(arr[i]>=0 && arr[j]<0){
          swap(arr[i],arr[j]);
          i++;
          j--;
      }
      else if(arr[i]<0 && arr[j]>0){
          j--;
      }
      else{
          j--;
      }
    }
}
void dutchAlgo(int arr[], int n){
    //ye wahi pepcoding wala algo h
}
void print(int arr[], int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    int n;
    cout<<"Enter size of the array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array\n";
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    solve(arr,n);
    print(arr,n);
    return 0;
}
