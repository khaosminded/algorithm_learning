#include<cstdio>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;
struct card
{
    char value[3];
    int num;
    card(){memset(value,0,sizeof(value));num=1;}


    int set(){if(1==scanf("%s",value) && value[0]!='#'){num=1;return 1;}return 0;}
    int cmp(const card &b)const
    {
        if(value[0]==b.value[0] || value[1]==b.value[1])return 0;
        return 1;
    }
    bool operator == (const card &b)const{return !cmp(b);}
    card operator = (const card &b){num=b.num;value[0]=b.value[0];value[1]=b.value[1];value[2]=b.value[2];}

};

struct pack
{
    card cards[52];
    int len;
    pack(){len=0;}
    int set(){for(int i=0;i<52;i++)if(!cards[i].set())return 0;len=52;return 1;}
    void l_shift(int b){for(int i=b;i<len-1;i++){cards[i]=cards[i+1];} len--;}//no validity check
    void pile(int a,int b)
    {
        cards[b].num+=cards[a].num;
        cards[a]=cards[b];
        l_shift(b);
    }
    bool isfinal()
    {
        for(int i=1;i<len;i++)
        {
            if(cards[i]==cards[i-1])return 0;
            if(i>=3)if(cards[i]==cards[i-3])return 0;
        }
        return 1;
    }
};

void result(const pack &a)
{
        cout<<a.len<<" "<<(a.len==1?"pile remaining:":"piles remaining:");
        for(int i=0;i<a.len;i++)printf(" %d",a.cards[i].num);
        printf("\n");
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    pack a;
    while(a.set())
    {//for(int i=0;i<a.len;i++)cout<<a.cards[i].value<<" ";cout<<endl;
        for(;;)
        {
            if(a.isfinal())break;
            for(int i=1;i<a.len;i++)
            {
                if(a.cards[i]==a.cards[i-1]){a.pile(i-1,i);break;}
                if(i>=3)if(a.cards[i]==a.cards[i-3]){a.pile(i-3,i);break;}

            }

        }
        result(a);
    }
    return 0;
}
//写给明天的我
//52叠 每个是个栈 压上低下牌不消失
