#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1000;
char a[maxn],b[maxn];
int d[maxn+1][maxn+1];
void dp()
{
    int an=strlen(a)-1,bn=strlen(b)-1;
    for(int i=0;i<an;i++)
      for(int j=0;j<bn;j++)
          if(a[i]==b[j])d[i+1][j+1]=d[i][j]+1;
          else d[i+1][j+1]=d[i+1][j]>=d[i][j+1]?d[i+1][j]:d[i][j+1];
    cout<<d[an][bn]<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif    
    while(fgets(a,sizeof(a),stdin))
    {
        fgets(b,sizeof(b),stdin);
        memset(d,0,sizeof(d));
        dp();
    }
    return 0;
}

