#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;
const int maxn=10000;
long long cnt=0;
struct node
{
    int v;
    node* l;
    node* r;
    node(){v=0;l=NULL;r=NULL;}
};
node n[maxn];
node * newnode(){node * u=&n[cnt++%maxn];u->l=u->r=NULL;return u;}
//cnt 别溢出很急很关键
//栈区别开大数组 往深层调用受不了
//static 好用
char s1[maxn*5],s2[maxn*5];
int i1[maxn],i2[maxn];
    stack<node*> s;
    stack<int> sums;
//栈大概也得弄出来
void build(int n,int* s1,int* s2,node* &s)
{
    if(n <= 0)return;
    int p;
    for(int i=0;i<n;i++)if(s1[i]==s2[n-1])
        {p=i;break;}
    s=newnode();
    build(p,s1,s2,s->l);//left
    build(n-p-1,s1+p+1,s2+p,s->r);//right
    s->v=s2[n-1];
}


int alter_DFS(node* n)
{
    int minsum=0x7fffffff,minv=0x7fffffff;
    s.push(n);
    sums.push(n->v);
    while(!s.empty())
    {
        node * t=s.top();   int sum=sums.top();
        s.pop();            sums.pop();
        if(sum>minsum){continue;}//已经超了 这支上的不再入栈
        if(t->l){s.push(t->l);sums.push(sum+t->l->v);}
        if(t->r){s.push(t->r);sums.push(sum+t->r->v);}
        if(0==t->l && 0==t->r)
        {//leaf
            if(minsum == sum)minv = minv>t->v ? t->v : minv;
            else minv = t->v;
            minsum = sum;
        }
    }
    return minv;
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    node * root;
    while(fgets(s1,sizeof(s1),stdin)&&fgets(s2,sizeof(s2),stdin))
    {
        int n=0;
        char* ptr1=s1,*ptr2=s2;
        for(int i=0;1==sscanf(ptr1,"%d",&i1[i]);i++)
        {
            while(*ptr1!=' '&&*ptr1!='\0')ptr1++;
            if(*ptr1==' ')ptr1++;
        }
        for(n=0;1==sscanf(ptr2,"%d",&i2[n]);n++)
        {
            while(*ptr2!=' '&&*ptr2!='\0')ptr2++;
            if(*ptr2==' ')ptr2++;
        }

        build(n,i1,i2,root);
        cout<<alter_DFS(root)<<endl;
    }
    return 0;
}
