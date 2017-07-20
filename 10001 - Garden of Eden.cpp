#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int r[8],s[32],a[32];
//r 规则 s 目标串 a 上一个状态
//0 0 0 r[0]
//0 0 1 r[1]
//0 1 0 r[2]
//0 1 1 r[3]
//1 0 0 r[4]
//1 0 1 r[5]
//1 1 0 r[6]
//1 1 1 r[7]
bool reachable(int n,int cur)
{
    if(cur+2==n)
    {//递归终止
        if(s[cur]==r[a[cur]*4+a[cur+1]*2+a[0]])
            if(s[cur+1]==r[a[cur+1]*4+a[0]*2+a[1]])
               return true;
        return false;
    }
    if(0==cur)
    {//递归开始
        for(int i=0;i<8;i++)
            if(r[i]==s[0])
            {
                a[0]=i&(1<<2)?1:0;
                a[1]=i&(1<<1)?1:0;
                a[2]=i%2;
                if(reachable(n,cur+1))return true;
            }
    }
    else
    {
        for(int i=0;i<8;i++)
            if(r[i]==s[cur])
                if(a[cur]==(i&(1<<2)?1:0) && a[cur+1]==(i&(1<<1)?1:0))
                {
                    a[cur+2]=i%2;

//                    for(int j=0;j<=cur+2;j++)cout<<a[j];cout<<endl;

                    if(reachable(n,cur+1))return true;
                }
    }

    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int id,n;
    while(2==scanf("%d %d",&id,&n))
    {
        for(int i=0;i<n;i++){cin>>(char&)s[i];s[i]-='0';}
        for(int i=0;i<8;i++)
            r[i]=id&(1<<i)?1:0;

//        cout<<"RULES:";for(int i=0;i<8;i++)cout<<r[i];cout<<endl;

        if(reachable(n,0))cout<<"REACHABLE\n";
        else cout<<"GARDEN OF EDEN\n";
    }
}
//哦淦 不一定是   XOR 的规则啊，就是给了个真值表
//哦凑2 长度为n 枚举的位数不固定
//o fa3 backtracking
