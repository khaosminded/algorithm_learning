#include<stdio.h>
#include<string.h>
const int maxn=2000;
int a[maxn];
int b[15];
int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    b[0]=1;
    for(int i=1;i<15;i++)b[i]=b[i-1]*2;
    for(int i=0;scanf("%d",&a[i])==1;i++)
    {
        if(0>a[i])break;
        for(int j=0;j<15;j++)if(b[j]>=a[i])
        {
            printf("Case %d: %d\n",i+1,j);
            break;
        }
    }
    return 0;
}
