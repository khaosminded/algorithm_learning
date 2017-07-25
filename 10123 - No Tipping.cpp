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
int pkg_p[maxpkg],pkg_w[maxpkg];
int L[maxpkg][3],R[maxpkg][3],M[maxpkg][2];
int ln,rn,mn,_n;
void test(int n=maxpkg)
{
    cout<<"L:"<<endl;
    for(int i=0;i<ln;i++)
        cout<<L[i][0]<<" "<<L[i][1]<<endl;
    cout<<endl<<"R:"<<endl;
    for(int i=0;i<rn;i++)
        cout<<R[i][0]<<" "<<R[i][1]<<endl;
    cout<<endl<<"M:"<<endl;
    for(int i=0;i<mn;i++)
        cout<<M[i][0]<<" "<<M[i][1]<<endl;
    cout<<endl<<"pkg:"<<endl;
    for(int i=0;i<n;i++)
        cout<<pkg_p[i]<<" "<<pkg_w[i]<<endl;
        cout<<endl;
}
int cmp_2(const void *_a,const void * _b)
{//compare
    int *a=(int *)_a,*b=(int *)_b;
    return abs(b[0]*b[1])-abs(a[0]*a[1]);
}

void init()
{//memset & sort
    ln=rn=mn=0;
    memset(L,0,sizeof(L));memset(R,0,sizeof(R));memset(M,0,sizeof(M));
    for(int i=0;i<pkg_n;i++)
    {
        if(pkg_p[i]<-1.5)L[ln][0]=pkg_p[i],L[ln++][1]=pkg_w[i];
        else if(pkg_p[i]>1.5)R[rn][0]=pkg_p[i],R[rn++][1]=pkg_w[i];
        else M[mn][0]=pkg_p[i],M[mn++][1]=pkg_w[i];
    }
    qsort(L,ln,sizeof(L[0]),cmp_2);
    qsort(R,rn,sizeof(R[0]),cmp_2);
}

int checkbalance(int n)
{//check front n pkgs
    float F1L=0,F1R=0,F2L=0,F2R=0;//支点F1 F2
    float G=brd_w*(brd_l-3)*(brd_l-3)/(8*brd_l),_G=brd_w*(brd_l+3)*(brd_l+3)/(8*brd_l);//杆提供的力矩
    for(int i=0;i<n;i++)
    {
        int &p=pkg_p[i],&w=pkg_w[i];
        if(p<-1.5)F1L+=w*fabs(p+1.5);
        if(p>1.5)F2R+=w*fabs(p-1.5);
        if(p<1.5)F2L+=w*fabs(p-1.5);
        if(p>-1.5)F1R+=w*fabs(p+1.5);

    }
    if(F1L+G <= F1R+_G && F2L+_G >= F2R+G)//is balance
        return F1L>F2R?1:2;
    return 0;
}

bool bck(int n,int l,int r)
{//back tracking
    int last=checkbalance(n);
    if(!last)return false;
    if(l==0 || r==0){_n=n;return true;}

    if(last==2)
    {
        for(int i=ln-1;i>=0;i--)if(!L[i][2])
        {
            pkg_p[n]=L[i][0],pkg_w[n]=L[i][1],L[i][2]=1;
            if(bck(n+1,l-1,r))return true;
            else {L[i][2]=0;break;}
        }
        for(int i=rn-1;i>=0;i--)if(!R[i][2])
        {
            pkg_p[n]=R[i][0],pkg_w[n]=R[i][1],R[i][2]=1;
            if(bck(n+1,l,r-1))return true;
            else {R[i][2]=0;break;}
        }

    }
    if(last==1)
    {
        for(int i=rn-1;i>=0;i--)if(!R[i][2])
        {
            pkg_p[n]=R[i][0],pkg_w[n]=R[i][1],R[i][2]=1;
            if(bck(n+1,l,r-1))return true;
            else {R[i][2]=0;break;}
        }
        for(int i=ln-1;i>=0;i--)if(!L[i][2])
        {
            pkg_p[n]=L[i][0],pkg_w[n]=L[i][1],L[i][2]=1;
            if(bck(n+1,l-1,r))return true;
            else {L[i][2]=0;break;}
        }
    }
    return false;
}

bool solve()
{//solve logic

    int n;
    for(n=0;n<mn;n++)
        pkg_p[n]=M[n][0],pkg_w[n]=M[n][1];
    if(ln>0 && rn>0)if(!bck(n,ln,rn))return false;
    n=_n;
    for(int i=0;i<ln;i++)if(!L[i][2])
    {
        pkg_p[n]=L[i][0],pkg_w[n++]=L[i][1];
        if(!checkbalance(n))return false;
    }
    for(int i=0;i<rn;i++)if(!R[i][2])
    {
        pkg_p[n]=R[i][0],pkg_w[n++]=R[i][1];
        if(!checkbalance(n))return false;
    }
    return true;
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
        init();
        //loaded
        printf("Case %d:\n",n++);
        if(solve())
            for(int i=pkg_n-1;i>=0;i--)printf("%d %d\n",pkg_p[i],pkg_w[i]);
        else printf("Impossible\n");

    }
}

//写麻烦了 关键点在排序 分左右两堆
//当前不可拿走 同堆力矩更大的必然不可拿走 就可以返回了
//而且应该是写错了…… 但是AC了……
