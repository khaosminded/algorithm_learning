#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int R=100;
int p[2*R*R][2];
int c[100][2];
int cntp=0;
void point_in_cycle()
{
    memset(p,0,sizeof(p));
    for(int x=0;x<=R;x++)
        for(int y=R;y>=-1*R;y--)if(x*x+y*y <= R*R)
            {p[cntp][0]=x;p[cntp][1]=y;cntp++;}
}

int main()
{
    freopen("input","r",stdin);
    freopen("output","w",stdout);

    int x1,y1,x,y,N;
    point_in_cycle();
//    for(int i=0;i<cntp;i++)
//        cout<<"x"<<p[i][0]<<"y"<<p[i][1]<<endl;
    while(cin>>N)
    {
        if(0==N)break;
        for(int i=0;i<2*N;i++)
            scanf("%d %d",&c[i][0],&c[i][1]);
//        for(int i=0;i<2*N;i++)
//            printf("%d %d\n",c[i][0],c[i][1]);

        for(int i=0;i<cntp;i++)
        {
            int cntu=0,cntd=0;
            x1=p[i][0],y1=p[i][1];
            for(int j=0;j<2*N;j++)
            {
                x=c[j][0],y=c[j][1];
                if(cntd>N || cntu>N)break;   //y=kx k=y1/x1(µ±x1>=0) y>y1/x1*x  y1*x-x1*y<0
                if(y1*x-x1*y<0)cntu++;//cherry is on the upper half
                if(y1*x-x1*y>0)cntd++;//otherwise
            }
            if(cntd+cntu==2*N && cntu==cntd){printf("%d %d\n",y1,-1*x1);break;}

        }
    }

    return 0;
}
