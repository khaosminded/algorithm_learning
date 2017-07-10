#include<cstdio>
#include<queue>
#include<stack>
#include<string.h>
#include<iostream>
using namespace std;
const int ln=2;
const int l[2]={3,1};//rule

struct card
{
    char value[3];
    card(){memset(value,0,sizeof(value));}
    int set(){if(1==scanf("%s",value) && value[0]!='#')return 1;return 0;}
    int cmp(const card &b)const
    {
        if(value[0]==b.value[0] || value[1]==b.value[1])return 0;
        return 1;
    }
    bool operator == (const card &b)const{return !cmp(b);}
    card operator = (const card &b){value[0]=b.value[0];value[1]=b.value[1];value[2]=b.value[2];}

};

struct piles
{

     int len;
     stack<card> s[52];
     piles(){len=52;}
     int set()
     {
         for(int i=0;i<len;i++)
         {
             card c;
             if(c.set())s[i].push(c);
             else return 0;
         }
         return 1;
     }
     bool canmove()
     {
         for(int i=1;i<len;i++)
         {
             for(int j=0;j<ln;j++)
                 if(i>=l[j])if(s[i-l[j]].top()==s[i].top())
                     return true;
         }
         return false;
     }
    void l_shift(int n)
    {
        stack<card> temp;
        for(int i=n;i<len-1;i++)
        {
            while(!s[i+1].empty())
            {
                temp.push(s[i+1].top());
                s[i+1].pop();
            }
            while(!temp.empty())
            {
                s[i].push(temp.top());
                temp.pop();
            }
        }
        len--;
    }
};


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(true)
    {
        piles p;
        if(0==p.set())break;
        mark1:while(p.canmove())
        for(int i=1;i<p.len;i++)
        {
            for(int j=0;j<ln;j++)
            if(i>=l[j])if(p.s[i].top()==p.s[i-l[j]].top())
            {
                p.s[i-l[j]].push(p.s[i].top());
                p.s[i].pop();
                if(p.s[i].empty())p.l_shift(i);
                goto mark1;
            }

        }
        cout<<p.len<<" "<<(p.len==1?"pile remaining:":"piles remaining:");
        for(int i=0;i<p.len;i++)cout<<" "<<p.s[i].size();cout<<endl;
    }
    return 0;
}


