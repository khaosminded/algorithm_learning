#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn=100;
const int maxp=15;
int bit[maxp];
int leds[maxn][maxp];
int tmp[maxn][maxp];
bool no_repeat(int N,int P)
{
    for(int i=0;i<P;i++)
        for(int j=0;j<N;j++)
            tmp[j][i]=leds[j][i]&bit[i];

    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            if(!memcmp(tmp[i],tmp[j],sizeof(int)*P))return false;

    return true;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        int P,N;
        cin>>P>>N;

        for(int i=0;i<N;i++)
            for(int j=0;j<P;j++)
                scanf("%d",&leds[i][j]);
        for(int i=0;i<=P;i++)
        {
            memset(bit,0,sizeof(bit));
            for(int j=0;j<i;j++)bit[P-j-1]=1;
            do
            {
                if(no_repeat(N,P)){cout<<i<<endl;goto fin;}
            }while(next_permutation(bit,bit+P));
        }
        fin:;
    }
    return 0;
}
