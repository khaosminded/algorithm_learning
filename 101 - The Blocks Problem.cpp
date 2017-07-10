#include<cstdio>
#include<queue>
#include<stack>
#include<string.h>
#include<iostream>
using namespace std;
int const maxn=25;
int bot[maxn];//基座上面block编号
int over[maxn];//上面一个block编号
int under[maxn];//下面一个block编号
int n;//一共多少blocks
void init(int a)
{
    if(a==0)return;
    init(over[a]);
    under[a]=0;
    over[a]=0;
    bot[a]=a;
}
int top(int a)
{
    while(over[a])a=over[a];
    return a;
}
int isfirst(int a)
{
    for(int i=1;i<=n;i++)
        if(bot[i]==a)return i;
    return false;
}
void moveaontob(int a,int b)
{
    int x=isfirst(a);
    if(x)bot[x]=0;
    else over[under[a]]=0;
    init(over[b]);
    init(over[a]);
    under[a]=b;
    over[a]=0;
    over[b]=a;
}
void moveaoverb(int a,int b)
{
    int x=isfirst(a);
    if(x)bot[x]=0;
    else over[under[a]]=0;
    init(over[a]);
    under[a]=top(b);
    over[under[a]]=a;
    over[a]=0;
}
void pileaontob(int a,int b)
{
    int x=isfirst(a);
    if(x)bot[x]=0;
    else over[under[a]]=0;
    init(over[b]);
    under[a]=b;
    over[b]=a;
}
void pileaoverb(int a,int b)
{
    int x=isfirst(a);
    if(x)bot[x]=0;
    else over[under[a]]=0;
    under[a]=top(b);
    over[under[a]]=a;
}
bool samestack(int a,int b)
{
    int x=over[a],y=over[b];
    while(x){if(b==x)return true;x=over[x];}
    while(y){if(a==y)return true;y=over[y];}
    return false;
}
void result()
{
    for(int i=1;i<=n;i++)
    {
        int x=bot[i];
        cout<<i-1<<":";//数据错一格 不要0
        while(x){cout<<" "<<x-1;x=over[x];}//数据错一格 不要0
        cout<<endl;
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){bot[i]=i;under[i]=0;over[i]=0;}//数据错一格 不要0

    char cmd1[10],cmd2[10];
    int a,b;
    while(4==scanf("%s%d%s%d",cmd1,&a,cmd2,&b))
    {
        a++;b++;//数据错一格 不要0
        if(a==b || samestack(a,b))
        {
            //cout<<"an illegal command"<<endl;
            continue;//illegal
        }
        if(0==strcmp(cmd1,"move"))
        {
            if(0==strcmp(cmd2,"onto"))moveaontob(a,b);
            moveaoverb(a,b);
        }
        if(0==strcmp(cmd1,"pile"))
        {
            if(0==strcmp(cmd2,"onto"))pileaontob(a,b);
            pileaoverb(a,b);
        }
        //cout<<cmd1<<" "<<a-1<<" "<<cmd2<<" "<<b-1<<endl;
        //result();cout<<endl;
    }
    result();
}
//move a onto b    a,b上面的全还原 a到b上
//move a over b    a上面的还原 a到b堆最上
//pile a onto b    b上面的还原 a和a上到b堆上
//pile a over b    a和a上到b堆上
