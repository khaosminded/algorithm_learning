#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxpkg=20;
int brd_l,brd_w,pkg_n;
int pkg_p[maxpkg],pkg_w[maxpkg],pkg_visting[maxpkg];
bool checkbalance()
{
    float F1L=0,F1R=0,F2L=0,F2R=0;//÷ßµ„F1 F2
    for(int i=0;i<pkg_n;i++)
    {
        if(!pkg_visting)
        {
            if(pkg_p<-1.5)F1L+=pkg_w*(-1.5-pkg_p);
            if(pkg_p>1.5)F1R+=pkg_w*(pkg_p-1.5);
            if(pkg_p<1.5)F2L+=pkg_w*(1.5-pkg_p);
            if(pkg_p>-1.5)F2R+=pkg_w*(1.5+pkg_p);
        }
    }


}
void solution(int cur)
{
    int is_possible=0;
    if(cur==0)for(int i=pkg_n;i>0;i--)
        for(int j=0;j<pkg_n;j++)if(pkg_visting[j]==i)
            printf("%d %d\n",pkg_p[j],pkg_w[j]);
    for(int i=0;i<cur;i++)
    {
        pkg_visting[i]=cur;
        if(checkbalance()){is_possible=1;solution(cur-1);}
        pkg_visting[i]=0;
    }
    if(cur==pkg_n && !is_possible)printf("Impossible\n");
}
int main()
{
//       freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n=1;
    while(scanf("%d %d %d",&brd_l,&brd_w,&pkg_n))
    {
        if(brd_l==0 && brd_w==0 && pkg_n==0)break;
        for(int i;i<pkg_n;i++)
            scanf("%d %d",&pkg_p[i],&pkg_w[i]);
        //loaded
        memset(pkg_visting,0,sizeof(pkg_visting));
        printf("Case %d:\n",n++);
        solution(pkg_n);
    }
}
