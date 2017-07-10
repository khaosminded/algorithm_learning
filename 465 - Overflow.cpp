#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#define MAXINT 0x7fffffff

#include "bign.h"
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    char ch1[maxn],ch2[maxn],ch3[maxn];
    while(scanf("%s",ch1)==1 && scanf("%s",ch2)==1 &&scanf("%s",ch3)==1)
    {
        //哦特么淦 前导0;
        char *c1=ch1,*c3=ch3;
        while(c1[0]=='0')c1++;
        while(c3[0]=='0')c3++;

        bign a,b,c,maxint=MAXINT;
        a=c1;b=c3;
        ch2[0]=='+' ? c=a+b :c=a*b;
        printf("%s %s %s\n",ch1,ch2,ch3);
        if( maxint < a) printf("first number too big\n");
        if( maxint < b) printf("second number too big\n");
        if( maxint < c) printf("result too big\n");
    }
    return 0;
}
