#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//2017年6月29日22:11:11
const int maxn=200;
char tree[maxn][maxn];

int firstC(int m,int l,int r)
{
    int j;

    for(j=l+1;j<r;j++)
        switch(tree[m][j])
        {
            case '|':break;
            case '-':break;
            case ' ':break;
            case '#':break;
            case '\n':break;
            case '\0':break;
            default:goto endsr;
        }
    return -1;
    endsr:return j;
}

void undraw(int m,int n)
{
    if(-1==n)return;//当前节点为空
    else
    {
        int l=n,r=n;//当前节点的子树可能范围
        if(tree[m+1][n]=='|')
        {
            while(tree[m+2][l]=='-')l--;
            while(tree[m+2][r]=='-')r++;
        }

        int cm=m+3,cn=l;
        cout<<tree[m][n];cout<<"(";
        while((cn=firstC(cm,cn,r))!=-1)
            undraw(cm,cn);//对当前节点每一个子节点递归
        cout<<")";
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,ch;
    cin>>n;getchar();

    for(int i=0;i<n;i++)
    {
        memset(tree,0,sizeof(tree));
        for(int j=0;;j++)
        {
            fgets(tree[j]+1,sizeof(tree[j])-1,stdin);//右错一格;
            if(tree[j][1]=='#')break;
        }
        cout<<"(";
        undraw(0,firstC(0,0,maxn-1));
        cout<<")"<<endl;
    }

    return 0;
}
//2017年6月30日02:44:18
