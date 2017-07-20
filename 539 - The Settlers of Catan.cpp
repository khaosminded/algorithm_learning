#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn=25;
int e[maxn][maxn];
int vis[maxn][maxn];
int n,m,maxlen;
void bfs(int u,int len)
{
    maxlen=len>maxlen? len:maxlen;
    for(int v=0;v<n;v++)if(e[u][v] && !vis[u][v])
    {
        vis[u][v]=vis[v][u]=1;
        bfs(v,len+1);
        vis[u][v]=vis[v][u]=0;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==m && n==0)break;
        //init
        int node1,node2;
        memset(e,0,sizeof(e));
        memset(vis,0,sizeof(vis));
        maxlen=0;
        //load
        for(int i=0;i<m;i++){
            scanf("%d %d",&node1,&node2);
            e[node1][node2]=e[node2][node1]=1;
        }
        //bfs
        for(int i=0;i<n;i++)bfs(i,0);
        cout<<maxlen<<endl;
    }
}
