#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
bool is_23(int *a,int sum,int n)
{
    if(5==n)return sum==23;
        return is_23(a,sum+a[n],n+1)||is_23(a,sum-a[n],n+1)||is_23(a,sum*a[n],n+1);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a[5];
    while(true)
    {
        bool ok=0;
        scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
        if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0)break;

        sort(a,a+5);
        do if(ok=is_23(a,a[0],1))break;
        while(next_permutation(a,a+5));
        printf(ok?"Possible\n":"Impossible\n");
    }
}
