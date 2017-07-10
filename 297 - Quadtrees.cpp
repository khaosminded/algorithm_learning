#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxlv=5;//4^5
const int maxt=4;
const int maxn=3000;
char s1[maxn],s2[maxn];

int pow_4(int lv)
{
    int n=1;
    for(int i=0;i<lv;i++)n*=4;
    return n;
}

int calculate(char * &t1,char * &t2,int lv)
{
    int sum=0;
    if(t1[0]=='f' || t2[0]=='f')//f* *f 5种
    {
        sum = pow_4(lv);
        if(t1[0]=='p')t1+=4;//fp p那头得略过子树
        if(t2[0]=='p')t2+=4;
    }
    if(t1[0]=='p' && t2[0]=='p')//pp
        for(int i=1;i<=maxt;i++)
            sum += calculate(++t1,++t2,lv-1);
    if(t1[0]=='p' && t2[0]=='e')//pe
        for(int i=1;i<=maxt;i++)
            sum += calculate(++t1,t2,lv-1);
    if(t1[0]=='e' && t2[0]=='p')//ep
        for(int i=1;i<=maxt;i++)
            sum += calculate(t1,++t2,lv-1);
    //以上都不是 则ee sum=0
    return sum;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    char *t1,*t2;
    for(int i=0;i<n;i++)
    {
        t1=s1;t2=s2;
        scanf("%s %s",t1,t2);
        cout<<"There are "<<calculate(t1,t2,maxlv)<<" black pixels."<<endl;
    }
}
