#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void print_permutation(int n,int* P,int *A,int cur)
{
    if(n==cur)
    {
        for(int i=0;i<n;i++)printf("%d ",P[i]);
        printf("\n");
    }
    else for(int i=0;i<n;i++)
    {
        int c1=0,c2=0;
        for(int j=0;j<cur;j++)if(A[i]==P[j])c1++;
        for(int j=0;j<n;j++)if(A[j]==A[i])c2++;
        if(c1<c2)
        {
            P[cur]=A[i];
            print_permutation(n,P,A,cur+1);
        }
    }
}


int main(){
    int A[10]={0,1,2,3,4,5,6,7,8,9};
    int P[10];
    print_permutation(10,P,A,0);


}
