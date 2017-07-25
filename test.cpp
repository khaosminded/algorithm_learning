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
bool checkbalance()
{
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
void bck(int &n)
{
    if(n==9)return;
    n+=1;bck(n++);
}
int main()
{
//       freopen("input.txt","w",stdout);
//   freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    int n=1;
//    while(3==scanf("%d %d %d",&brd_l,&brd_w,&pkg_n))
//    {
//        if(brd_l==0 && brd_w==0 && pkg_n==0)break;
//        for(int i=0;i<pkg_n;i++)
//            scanf("%d %d",&pkg_p[i],&pkg_w[i]);
//        loaded
//        memset(pkg_visting,0,sizeof(pkg_visting));
//        printf("Case %d:\n",n++);
//        cout<<checkbalance()<<endl;
//    }
//cout<<"20 2 20"<<endl;
//int a=3,x=0;
//for(int i=1;i<=20;i++)
//{
//    x=2*(x*3.5+3);
//    cout<<(i%2?-1:1)*2<<" "<<x<<endl;
//}
//cout<<"0 0 0"<<endl;
int n=0;
bck(n);cout<<n;
}
