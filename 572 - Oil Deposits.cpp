#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
//2017��6��30��15:22:43
const int MAXN=100;
int mat[MAXN][MAXN];
int vis[MAXN][MAXN];
void dfs(int x,int y)
{
    if(!mat[x][y] || vis[x][y])return ;
    vis[x][y]=1;
    dfs(x-1,y+1);dfs(x,y+1);dfs(x+1,y+1);
    dfs(x-1,y);             dfs(x+1,y);
    dfs(x-1,y-1);dfs(x,y-1);dfs(x+1,y-1);

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int x,y;
    char s[MAXN];
    while(scanf("%d %d",&x,&y))
    {
        memset(mat,0,sizeof(mat));
        memset(vis,0,sizeof(vis));
        if(0 == x)break;
        for(int i=0;i<x;i++)
        {
            scanf("%s",s);
            for(int j=0;j<y;j++)
                mat[i+1][j+1] = s[j]-'*';//��һȦ
        }
        int c=0;
        for(int i=1;i<=x;i++)//����
            for(int j=1;j<=y;j++)//���ʹ����ڽ�ȫ����
                if(!vis[i][j] && mat[i][j]){c++;dfs(i,j);}
        printf("%d\n",c);
    }
    return 0;

}
//2017��6��30��15:48:32
