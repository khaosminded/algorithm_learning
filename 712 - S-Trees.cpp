#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


void s_tree(char * t,char * c)
{
    int n=strlen(c),p=1;
    for(int i=0;i<n;i++)
        if(c[i]=='1')p=p*2;
            else p=p*2-1;
    cout<<t[p-1];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char command[7+1];
    char tree[128+1];
    int n;
    for(int i=1;;i++)
    {
        cin>>n;
        if(n==0)break;
        cout<<"S-Tree #"<<i<<":"<<endl;
        for(int j=0;j<n;j++)cin>>command;
        cin>>tree;
        cin>>n;
        for(int j=0;j<n;j++)
            {cin>>command;s_tree(tree,command);}
        cout<<endl<<endl;
    }
    return 0;
}
