#include<iostream>
using namespace std;
class Array
{  
private:
    int *A;
    int size;
    int length;
    void Swap(int *x, int *y);
public:
Array()
{
    size=10;
    length=0;
    A=new int[size];
}
Array(int sz)
{ 
    size=sz;
    length=0;
    A=new int[size];
}
~Array()
{
    delete []A;
}
void Display();
void Append(int x);
void Insert(int index,int x);
int Delete(int index);
int LinearSearch(int key);
int BinarySearch( int key);
int Get(int index);
void Set(int index, int x);
int Max();
int Min();
int Sum();
float Avg();
void Reverse();
void Reverse2();
void InsertSort(int x);
char IsSorted();
void Rearrange();
 Array* Merge(Array arr2);
 Array* Union(Array arr2);
 Array* Difference(Array arr2);
 Array* Intersection(Array arr2);
};
void Array::Display()
{   int i;
    for(i=0;i<length;i++)
    cout<<A[i]<<" ";
    cout<<endl;
}
void Array::Append(int x)// here x is the value to be added at the end of the array
{
    if(length<size)
    A[length++]=x;
}
void Array::Insert(int index,int x) // this function will take the value(x) from the user to be added at the given index
{   int i;
    if(index>=0 && index<=length)
    {
        for(i=length;i>index;i--)
        A[i]=A[i-1];
        A[index]=x;
        length++;
    }
}
int Array::Delete(int index)
{
   int i,x=0;
   if(index>=0 && index<length)
   {
    x=A[index];
    for(i=index;i<length-1;i++)
    A[i]=A[i+1];
    length--;
    return x;
   }
return x;
}
void Array::Swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int Array::LinearSearch(int key)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(A[i]==key)
        Swap(&A[i],&A[0]); //improving linear search by using method of moving to fron
        //Swap(&A[i],&A[i-1]) //improving linear search by method of transposition
        return i;
    }
return -1;
}
int Array::BinarySearch(int key)//func for binary search using normal method
{
   int l,h,mid,i;
   l=0;
   h=length-1;
   while(l<=h)
   {
       mid=(l+h)/2;
       if(A[mid]==key)
       return mid;
       else if(key<A[mid])
       h=mid-1;
       else
       l=mid+1;
   }
return -1;
}
/*int RbinSearch(int A[],int l,int h,int key) // func for binary search using recursions
{
   int i,mid;
   if(l<=h)
   {
       mid=(l+h)/2;
       if(key==A[mid])
       return mid;
       else if(key<A[mid])
       return RbinSearch(A,l,mid-1,key);
       else if(key>A[mid])
       return RbinSearch(A,mid+1,h,key);
   }
return -1;
}
*/
int Array::Get(int index) // get func return the value at the given index in Array
{ 
  if(index>=0 && index<length)
  return A[index];
}
void Array::Set(int index, int x)
{
   if(index>=0 && index<length)
   A[index]=x;
}
int Array::Max()
{
    int i,max;
    max=A[0];
    for(i=1;i<length;i++)
    {
       if(A[i]>max)
       max=A[i];
    }
return max;
}
int Array::Min()
{
    int i,min;
    A[0]=min;
    for(i=1;i<length;i++)
    {
        if(A[i]<min)
        min=A[i];
    }
return min;
}
int Array::Sum()
{
    int i,sum=0;
    for(i=0;i<length;i++)
    sum+=A[i];
    return sum;
}
float Array::Avg()
{
   return (float)Sum()/length;
}

void Array::Reverse() //reversing the array using another array 
{
  int *B;
  int i,j;
  B=(int *)malloc(length*sizeof(int));
  for(i=length-1,j=0;i<=0;i--,j++)
     B[j]=A[i];
  for(i=0;i<length;i++)
     B[i]=A[i];

  delete []B; //to free heap memory
}
void Array::Reverse2() //using swap function
{  int i,j;
   for(i=0,j=length-1;i<length;i++,j--)
   {
     Swap(&A[i],&A[j]);
   }
}

void Array::InsertSort(int x)
{
   int i=length-1;
   if(length==size)
   return;
   while(i>=0 && A[i]>x)
   {
      A[i+1]=A[i];
      i--;
   }
   A[i+1]=x;
   length++;
}
char Array::IsSorted() //This function returns Y if the array is sorted and n if not sorted
{
   int i;
   for(i=0;i<length;i++)
   {
       if(A[i+1]>A[i])
       return 'Y';
   } 
return 'N';
}
void Array::Rearrange() // this function arranges negative integers on the left side and positives on the right side
{
  int i,j;
  i=0;j=length-1;
  while(i<j)
  {
    while(A[i]<0){i++;}
    while(A[j]>0){j--;}
    if(i<j) Swap(&A[i],&A[j]);
  }
}

Array* Array::Merge(Array arr2)
{
 int i,j,k;
 i=j=k=0;
 
 Array *arr3=new Array(length+arr2.length);
 
 while(i<length && j<arr2.length)
 {
 if(A[i]<arr2.A[j])
 arr3->A[k++]=A[i++];
 else
 arr3->A[k++]=arr2.A[j++];
 }
 for(;i<length;i++)
 arr3->A[k++]=A[i];
 for(;j<arr2.length;j++)
 arr3->A[k++]=arr2.A[j];
 arr3->length=length+arr2.length;
 
 return arr3;
}

// SET operations on Array
Array * Array::Union(Array arr2) // union excludes duplicates i.e. duplicates are copied only once
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<length && j<arr2.length)
    {
       if(A[i]<arr2.A[j])
        arr3->A[k++]=A[i++];
       else if(A[i]>arr2.A[j])
        arr3->A[k++]=arr2.A[j++];
       else
       {
         arr3->A[k++]=A[i++];
         j++;
       }
    }
    for(;i<length;i++)
    arr3->A[k++]=A[i];
    for(;j<arr2.length;j++)
    arr3->A[k++]=A[j];
    arr3->length=k;
    arr3->size=20;
return arr3;
}

Array* Array::Intersection(Array arr2)
{
 int i,j,k;
 i=j=k=0;
 
 Array *arr3=new Array(length+arr2.length);
 
 while(i<length && j<arr2.length)
 {
 if(A[i]<arr2.A[j])
 i++;
 else if(arr2.A[j]<A[i])
 j++;
 else if(A[i]==arr2.A[j])
  {
   arr3->A[k++]=A[i++];
   j++;
  }
 }
 
 arr3->length=k;
 
return arr3;
}

Array* Array::Difference(Array arr2)
{
 int i,j,k;
 i=j=k=0;
 
 Array *arr3=new Array(length+arr2.length);
 
 while(i<length && j<arr2.length)
 {
 if(A[i]<arr2.A[j])
 arr3->A[k++]=A[i++];
 else if(arr2.A[j]<A[i])
 j++;
 else
 {
 i++;
 j++;
 }
 }
 for(;i<length;i++)
 arr3->A[k++]=A[i];
 
 
 arr3->length=k;
 
 return arr3;
}

int main()
{
 Array *arr1;
 int ch,sz;
 int x,index;
 
 cout<<"Enter Size of Array";
 scanf("%d",&sz);
 arr1=new Array(sz);
 
 do
 {
 cout<<"\n\nMenu\n";
 cout<<"1. Insert\n";
 cout<<"2. Delete\n";
 cout<<"3. Search\n";
 cout<<"4. Sum\n";
 cout<<"5. Display\n";
 cout<<"6.Exit\n";
 
 cout<<"enter you choice ";
 cin>>ch;
 
 switch(ch)
 {
 case 1: cout<<"Enter an element and index ";
 cin>>x>>index;
 arr1->Insert(index,x);
 break;
 case 2: cout<<"Enter index ";
 cin>>index;
 x=arr1->Delete(index);
 cout<<"Deleted Element is"<<x;
 break;
 case 3:cout<<"Enter element to search ";
 cin>>x;
 index=arr1->LinearSearch(x);
 cout<<"Element index "<<index;
 break;
 case 4:cout<<"Sum is "<<arr1->Sum();
 break;
 case 5:arr1->Display();
 
 }
 }while(ch<6);
 return 0;

}
