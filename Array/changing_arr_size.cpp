#include<stdlib.h>
#include <iostream>

using namespace std;
int main()
{
    int *p,*q;
    p=new int[5];
    p[0]=2;
    p[1]=3;
    p[2]=4;
    p[3]=5;
    p[4]=6;
   
    q=(int*)malloc(10*sizeof(int));
    for(int i=0;i<5;i++)
    q[i]=p[i];
    delete []p;
    p=q;
    q=NULL;
    for(int i=5;i<10;i++)
    p[i]=i+4;
    for(int i=0;i<10;i++)
    cout<<p[i]<<endl;
    
    return 0;
}