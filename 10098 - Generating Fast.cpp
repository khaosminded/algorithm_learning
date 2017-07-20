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
