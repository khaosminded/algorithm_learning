#include<cstdio>
#include<queue>
#include<stack>
#include<string.h>
#include<iostream>
using namespace std;
const int len=10;
int right_ptr[len+2],left_ptr[len+2];
void link(int X,int Y)
{
    right_ptr[X]=Y;
    left_ptr[Y]=X;
}
void result()
{
        int x=right_ptr[0];
        for(int i=0;i<len-1;i++)
            {cout<<x<<"<=>";x=right_ptr[x];}
        cout<<x<<endl;
}
int main()
{
    for(int i=0;i<=len;i++)
        right_ptr[i]=i+1;
    for(int i=1;i<=len+1;i++)
        left_ptr[i]=i-1;

    result();

    char type[1];
    int X,Y;
    while(3==scanf("%s%d%d",type,&X,&Y))
    {
        link(left_ptr[X],right_ptr[X]);//拆
        if(type[0]=='A')
        {
            link(left_ptr[Y],X);//X和Y左侧连
            link(X,Y);//X和Y连

        }else
        {
             link(X,right_ptr[Y]);
             link(Y,X);
        }
        int x=right_ptr[0];
        result();
    }
    return 0;
}


