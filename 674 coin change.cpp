#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int maxn=7500;
long long d[maxn+1];
int coins[5]={1,5,10,25,50};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif    
    memset(d,0,sizeof(d));
    d[0]=1;
    for(int i=0;i<5;i++)
      for(int j=coins[i];j<=maxn;j++)
        d[j]+=d[j-coins[i]];
    int n;
    while(scanf("%d",&n)==1)
        cout<<d[n]<<endl;
    return 0;
}
//计算顺序很重要哦 1的刷一遍5的刷一遍 10的刷一遍以此类推 不重
    
