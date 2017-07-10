#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    //freopen("input2.txt","r",stdin);
    //freopen("output2.txt","w",stdout);
    string tapeline;
    char ch=0;
    while(getline(cin,tapeline))
    {
        if(tapeline[2]=='o')ch+=64;
        if(tapeline[3]=='o')ch+=32;
        if(tapeline[4]=='o')ch+=16;
        if(tapeline[5]=='o')ch+=8;
        if(tapeline[7]=='o')ch+=4;
        if(tapeline[8]=='o')ch+=2;
        if(tapeline[9]=='o')ch+=1;
        if(ch)printf("%c",ch);
        ch=0;
    }
    return 0;
//0123456789
//| oooo.ooo|

}
