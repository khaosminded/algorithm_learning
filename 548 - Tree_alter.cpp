#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int maxn=10000;
int cnt=0;
struct node
{
    int v;
    node* l;
    node* r;
    node(){v=0;l=NULL;r=NULL;}
};
node n[maxn];
node * newnode(){node * u=&n[cnt++];u->l=u->r=NULL;return u;}
void build(int n,char* s1,char* s2,node* &s)
{
    if(n <= 0)return;
    int p = strchr(s1,s2[n-1])-s1;//offset of root in s1
    s=newnode();
    build(p,s1,s2,s->l);//left
    build(n-p-1,s1+p+1,s2+p,s->r);//right
    s->v=s2[n-1];
}
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
void BFS(node* s)
{
    queue<node*> q;
    q.push(s);
    while(!q.empty())
    {
        if(q.front()->l)q.push(q.front()->l);
        if(q.front()->r)q.push(q.front()->r);
        printf("%c",q.front()->v);
        q.pop();
    }
}
void DFS(node* n)
{
    stack<node*> s;
    s.push(n);
    while(!s.empty())
    {
        node * t=s.top();
        s.pop();
        if(t->l)s.push(t->l);
        if(t->r)s.push(t->r);
        printf("%c",t->v);
    }
}
void forder(node* n)
{
    if(!n)return;
    printf("%c",n->v);
    forder(n->l);
    forder(n->r);
}

int alter_DFS(node* n)
{
    int minsum=0x7fffffff,minv=0x7fffffff;
    stack<node*> s;
    stack<int> sums;
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
    return minv;//something is wrong here
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node * root;
    char s1[maxn],s2[maxn];
    int i1[maxn],i2[maxn];
    while(gets(s1)&&gets(s2))
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

}
