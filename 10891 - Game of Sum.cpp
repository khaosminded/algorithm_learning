#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100;
int D[maxn][maxn],vis[maxn][maxn];
int V[maxn];
int d(int i,int j)
{
    int &ans=D[i][j];
    if(i==j)return ans=V[i];
    if(vis[i][j])return ans;

    int sum=0;
    for(int a=i;a<=j;a++)sum+=V[a];

    vis[i][j]=1;ans=sum;
    for(int k=i;k<j;k++)
    {
        ans= ans > sum-d(i,k) ? ans : sum-d(i,k);
        ans= ans > sum-d(k+1,j) ? ans : sum-d(k+1,j);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif    
    int n;
    while(scanf("%d",&n),n)
    {
        int sum=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            scanf("%d",&V[i]),sum+=V[i];   
        d(0,n-1);
        cout<<2*D[0][n-1]-sum<<endl;
    }
    return 0;
}
