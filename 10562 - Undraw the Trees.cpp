#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//2017��6��29��22:11:11
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
    if(-1==n)return;//��ǰ�ڵ�Ϊ��
    else
    {
        int l=n,r=n;//��ǰ�ڵ���������ܷ�Χ
        if(tree[m+1][n]=='|')
        {
            while(tree[m+2][l]=='-')l--;
            while(tree[m+2][r]=='-')r++;
        }

        int cm=m+3,cn=l;
        cout<<tree[m][n];cout<<"(";
        while((cn=firstC(cm,cn,r))!=-1)
            undraw(cm,cn);//�Ե�ǰ�ڵ�ÿһ���ӽڵ�ݹ�
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
            fgets(tree[j]+1,sizeof(tree[j])-1,stdin);//�Ҵ�һ��;
            if(tree[j][1]=='#')break;
        }
        cout<<"(";
        undraw(0,firstC(0,0,maxn-1));
        cout<<")"<<endl;
    }

    return 0;
}
//2017��6��30��02:44:18
