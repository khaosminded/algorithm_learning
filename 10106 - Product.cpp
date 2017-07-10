#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include"bign.h"
using namespace std;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char ch[maxn],ch2[maxn];
    bign a;
    bign b;
    bign c;
    while(scanf("%s",ch)==1 && scanf("%s",ch2)==1)
    {
        a=ch;b=ch2;c=a*b;
        cout<<c<<endl;
    }


    return 0;
}
