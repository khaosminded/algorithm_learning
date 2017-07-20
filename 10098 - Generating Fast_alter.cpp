#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
void print_permutation(int n,char *P,char* A,int cur)
{
    int i,j,c1,c2;
    if(cur == n)printf("%s\n",A);
    else for(i=0;i<n;i++)
    {
        for(j=0;j<cur;j++)if(A[j]==P[i])c1++;
        for(j=0;j<n;j++)if(P[i]==P[j])c2++;
        if(c1<c2)
        {
            A[cur]=P[i];
            print_permutation(n,P,A,cur+1);

        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N;
    char s[11];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",s);
        sort(s,s+strlen(s));
        do{printf("%s\n",s);}while(next_permutation(s,s+strlen(s)));
        printf("\n");
    }
}
