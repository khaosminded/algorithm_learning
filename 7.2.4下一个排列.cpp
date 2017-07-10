#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
//    cout<<10*9*8*7*6*5*4*3*2;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,p[100];scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    sort(p,p+n);
    do{
        for(int i=0;i<n;i++)
            printf("%d ",p[i]);
        printf("\n");

    }while(next_permutation(p,p+n));
    return 0;
}
