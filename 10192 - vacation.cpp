#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int maxn=111;
char v1[maxn],v2[maxn];
int d[maxn][maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif    
    int cn=1;
    while(true)
    {
        int n1=0,n2=0;
        while(v1[n1++]=getchar())
            if(v1[n1-1]=='\n'||v1[n1-1]=='\r'){v1[--n1]='\0';break;}
        if(v1[0]=='#')break;
        while(v2[n2++]=getchar())
            if(v2[n2-1]=='\n'||v2[n2-1]=='\r'){v2[--n2]='\0';break;}
         
        memset(d,0,sizeof(d));
        //int n1=strlen(v1),n2=strlen(v2);
        for(int i=1;i<=n1;i++)
          for(int j=1;j<=n2;j++)
          {
            if(v1[i-1]==v2[j-1])
              d[i][j]=d[i-1][j-1]+1;
            else if(d[i][j-1]>=d[i-1][j])
              d[i][j]=d[i][j-1];
            else
              d[i][j]=d[i-1][j];
          }
    cout<<"Case #"<<cn<<": you can visit at most "<<d[n1][n2]<<" cities."<<endl;cn++;
    }
    return 0;
}
