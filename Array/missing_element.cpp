#include<iostream>
using namespace std;
/*struct Array
{
    int *A;
    int size;
    int length;
};
*/
int main()
{ //single missing element
  int A[]={5,6,8,9,10,11,12,13,14};
  int i;
  int l=A[0];
   int h=A[8];
   int diff=l-0;
 for(i=0;i<9;i++)
  {
      if(A[i]-i!=diff)
        { 
            cout<<"missing element is:"<<diff+i<<endl;
          break;
        }
  }
 
  //mutiple missing elements
  int B[]={6,7,9,11,14,16,17,19};
  int l2=B[0];
  int h2=B[7];
  int diff2=l2-0;
  for(i=0;i<8;i++)
  {
      if(B[i]-i!=diff2)
        {   
            while(diff2<B[i]-i)
            {
                cout<<diff2+i<<" ";
                diff2++;
            }

        }
  }

  return 0;    
}
