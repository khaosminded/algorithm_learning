#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
const int maxpkg=20;
int brd_l,brd_w,pkg_n;
int pkg_p[maxpkg],pkg_w[maxpkg],pkg_visting[maxpkg];
int fa[maxpkg];
void mysort()
{//tested //力矩从大到小 左右左右排列 F1-F2之间木块最后
    int * p=pkg_p,* w=pkg_w;
    for(int i=pkg_n;i>0;i--)
        for(int j=0;j<i;j++)
        {
            if(fabs(p[i]*w[i]) > fabs(p[j]*w[j]))
            {
                p[i]=p[i]^p[j];p[j]=p[i]^p[j];p[i]=p[i]^p[j];
                w[i]=w[i]^w[j];w[j]=w[i]^w[j];w[i]=w[i]^w[j];
            }
        }

    int cnt1=0,cnt2=0,cnt3=0,temp1[20][2],temp2[20][2],temp3[20][2];
    for(int i=0;i<pkg_n;i++)
    {
        if(p[i]<=1.5 && p[i]>=-1.5)temp3[cnt3][0]=p[i],temp3[cnt3][1]=w[i],cnt3++;
        if(p[i]<-1.5)temp1[cnt1][0]=p[i],temp1[cnt1][1]=w[i],cnt1++;
        if(p[i]>1.5)temp2[cnt2][0]=p[i],temp2[cnt2][1]=w[i],cnt2++;
    }

    for(int i=0;i<cnt3;i++)
        p[pkg_n-i-1]=temp3[i][0],w[pkg_n-i-1]=temp3[i][1];

    for(int j=0,k=0;j+k<cnt1+cnt2;)
    {
        if(j<cnt1)p[j+k]=temp1[j][0],w[j+k]=temp1[j][1],j++;
        if(k<cnt2)p[j+k]=temp2[k][0],w[j+k]=temp2[k][1],k++;
    }
//    for(int i=0;i<pkg_n;i++)cout<<pkg_p[i]<<" "<<pkg_w[i]<<endl;
}
bool checkbalance()
{//tested
    float F1L=0,F1R=0,F2L=0,F2R=0;//支点F1 F2
    float G=brd_w*(brd_l-3)*(brd_l-3)/(8*brd_l),_G=brd_w*(brd_l+3)*(brd_l+3)/(8*brd_l);//杆提供的力矩
    for(int i=0;i<pkg_n;i++)
    {
        int &p=pkg_p[i],&w=pkg_w[i];
        if(!pkg_visting[i])
        {
            if(p<-1.5)F1L+=w*fabs(p+1.5);
            if(p>1.5)F2R+=w*fabs(p-1.5);
            if(p<1.5)F2L+=w*fabs(p-1.5);
            if(p>-1.5)F1R+=w*fabs(p+1.5);
        }
    }
    if(F1L+G <= F1R+_G && F2L+_G >= F2R+G)//is balance
        return true;
    return false;
}
bool solution(int cur)
{
    if(cur==0)return true;
    bool balance=checkbalance();
    if(balance)for(int i=0;i<pkg_n;i++)
        if(!pkg_visting[i])
        {
            pkg_visting[i]=cur;
            if(balance && solution(cur-1)){fa[cur-1]=i;return true;}
            pkg_visting[i]=0;
        }
    return false;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n=1;
    while(3==scanf("%d %d %d",&brd_l,&brd_w,&pkg_n))
    {
        if(brd_l==0 && brd_w==0 && pkg_n==0)break;
        for(int i=0;i<pkg_n;i++)
            scanf("%d %d",&pkg_p[i],&pkg_w[i]);
        //loaded
        mysort();
        memset(pkg_visting,0,sizeof(pkg_visting));
        printf("Case %d:\n",n++);

        if(solution(pkg_n))
            for(int i=pkg_n-1;i>=0;i--)
                printf("%d %d\n",pkg_p[fa[i]],pkg_w[fa[i]]);
        else printf("Impossible\n");
    }
}

