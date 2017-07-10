#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn=1000;
int pile[maxn];
void drop(int n)
{
    int leaf;cin>>leaf;getc(stdin);
    if(leaf==-1)return;
    pile[maxn/2+n]+=leaf;
    drop(n-1);
    drop(n+1);
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    memset(pile,0,sizeof(pile));
    char ch;
    for(int i=1;(ch=getc(stdin))!='-';i++)
    {
        ungetc(ch,stdin);
        drop(0);
        cout<<"Case "<<i<<":"<<endl;
        int k=0,j=0,s=0,e=0;
        while(pile[k]==0)k++;
        s=k;
        while(pile[k]!=0)k++;
        e=k-1;
        for(j=s;j<e;j++)
            cout<<pile[j]<<" ";
        cout<<pile[j];

        cout<<endl<<endl;
        memset(pile,0,sizeof(pile));
    }

    return 0;
}
