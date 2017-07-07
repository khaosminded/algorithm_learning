#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int R=100;
int** point_in_cycle()
{
    static int p[2*R*R][2];
    int cnt=0;
    memset(p,0,sizeof(p));
    for(int x=0;x<=R;x++)
        for(int y=R;y>=-1*R;y--)
            if(x*x+y*y <= R*R){p[i][0]=x;p[i][1]=y;}
    return p;
}


int main()
{
    int ** p;
    int cntu=0,cntd=0;
    p=point_in_cycle();

    getAB();
    //eachAB
    for(int i=0;p[i][0]!=0 || p[i][1]!=0 ;i++)
    {
        int x=p[i][0];
        int y=p[i][1];
        if(A*x+B*y>0)cntu++;
        if(A*x+B*y<0)cntd++;
    }
    if(cntd+cntu== 2*N)printf("%d %d",x,y);
    if(cntd>N || cntu>N)break;
}
