#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

int main()
{
    int A[2][3]={{1,3,5},{2,4,6}};
    int *B[3];
    int i,j;
    
    for(i=0;i<2;i++)
    {   for(j=0;j<3;j++)
        printf("%d ",A[i][j]);
        printf("\n");
    }
    B[0]=new int[4];
    B[1]=new int[4];
    B[2]=new int[4];
    int **C;
    C=new int*[3];
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));

    return 0;
}
