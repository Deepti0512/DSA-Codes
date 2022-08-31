#include<iostream>
using namespace std;
 void find_duplicates_sortedlist(int A[])
   { int i,j;
    for(i=0;i<10;i++)
    {  
        if(A[i]==A[i+1])
       {
          j=i+1;
          while(A[j]==A[i])
          j++;
          cout<<A[i]<<" is appearing "<<j-i<<" times."<<endl;
          i=j-1;
       }
    }  
   }  
 void find_duplicates_unsortedlist(int A[],int n)  //similar aproach for finding duplicates in string
 {
    int i,j;
    for(i=0;i<n-1;i++)
    {  int count =1;
         if(A[i]!=-1)
         {
            for (j=i+1;j<n;j++)
            {
              if(A[i]==A[j])
              {
                 count++;
                 A[j]=-1;
              }
            }
         if(count>1)
         cout<<A[i]<<" is appearing "<<count<<" times."<<endl;   
         }
    }
   
 }
int main()
{   int j;
    int A[12];
    cout<<"Enter the elements in array(in sorted order & max 12) "<<endl;
    for(int i=0;i<12;i++) 
    cin>>A[i];
    find_duplicates_sortedlist(A);
    int B[10]={1,9,4,0,3,5,9,3,5,2};
    find_duplicates_unsortedlist(B,10);
return 0;
}
