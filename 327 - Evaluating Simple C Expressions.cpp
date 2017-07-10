#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn=1000;
int value[26][2];
char s[maxn];
void init()
{
    memset(value,0,sizeof(value));
    for(int i=1;i<=26;i++)
        value[i-1][0]=i;
}
//bool a_unary(int len ,char *s)\
//{
//    if(len<3)return false;
//    if(s[0]==s[1])return true;
//    if(s[1]==s[2])return true;
//    return false;
//}

//int evaluating(int len,char * s)错了搞成右结合 不符合减法结合律
//{
//    int sum=0;
//    if(len<=0)return 0;
//
//    if(!a_unary(len,s))//a+b||a-b
//    {
//        if(s[1]=='+')sum=value[s[0]-'a'][0]+evaluating(len-2,s+2);//a+b
//        else sum=value[s[0]-'a'][0]-evaluating(len-2,s+2);//a-b
//        value[s[0]-'a'][1]=1;
//    }
//    else if(isalpha(s[0]))//a++||a--   len>=3
//    {
//        if(s[1]=='+')//a++-
//            sum=value[s[0]-'a'][0]++-evaluating(len-4,s+4);
//        else//a--+
//            sum=value[s[0]-'a'][0]--+evaluating(len-4,s+4);
//        value[s[0]-'a'][1]=1;
//    }
//    else//++a||--a
//    {
//        if(s[0]=='+')//++a
//        {
//            if(s[3]=='-')//++a-
//                sum=++value[s[2]-'a'][0]-evaluating(len-4,s+4);
//            else//++a+
//                sum=++value[s[2]-'a'][0]+evaluating(len-4,s+4);
//        }
//        else//--a
//        {
//            if(s[3]=='-')//--a-
//                sum=--value[s[2]-'a'][0]-evaluating(len-4,s+4);
//            else//--a+
//                sum=--value[s[2]-'a'][0]+evaluating(len-4,s+4);
//        }
//        value[s[2]-'a'][1]=1;
//    }
//    return sum;
//}
bool a_unary(int len ,char *s)
{
    if(len<3)return false;
    if(s[len-2]==s[len-1])return true;//a++
    if(s[len-3]==s[len-2])return true;//++a
    return false;
}
int evaluating(int len,char * s)//左结合
{
    int sum=0;
    if(len<=0)return 0;

    if(!a_unary(len,s))//b+a||b-a
    {
        if(len==1) sum=value[s[len-1]-'a'][0];//0a
        else if(s[len-2]=='+')sum = evaluating(len-2,s)+value[s[len-1]-'a'][0];//b+a
        else if(s[len-2]=='-')sum = evaluating(len-2,s)-value[s[len-1]-'a'][0];//b-a

        value[s[len-1]-'a'][1]=1;
    }
    else if(isalpha(s[len-1]))//++a ||--a   len>=3
    {
        if(len==3)
        {
            if(s[len-3]=='+')sum=++value[s[len-1]-'a'][0];
            if(s[len-3]=='-')sum=--value[s[len-1]-'a'][0];
        }
        else if(s[len-4]=='+')//+--a
            sum=evaluating(len-4,s)+--value[s[len-1]-'a'][0];
        else if(s[len-4]=='-')//-++a
            sum=evaluating(len-4,s)-++value[s[len-1]-'a'][0];
        value[s[len-1]-'a'][1]=1;
    }
    else//a++ ||a--
    {
        if(s[len-1]=='+')//a++
        {

            if(len==3)sum=value[s[len-3]-'a'][0]++;//0a++
            else if(s[len-4]=='+')//+a++
                sum=evaluating(len-4,s)+value[s[len-3]-'a'][0]++;
            else if(s[len-4]=='-')//-a++
                sum=evaluating(len-4,s)-value[s[len-3]-'a'][0]++;

        }
        else//a--
        {
            if(len==3)sum=value[s[len-3]-'a'][0]--;//0a--
            else if(s[len-4]=='+')//+a--
                sum=evaluating(len-4,s)+value[s[len-3]-'a'][0]--;
            else if(s[len-4]=='-')//-a--
                sum=evaluating(len-4,s)-value[s[len-3]-'a'][0]--;
        }
        value[s[len-3]-'a'][1]=1;
    }
    return sum;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char ch;
    while((ch=getc(stdin))!=EOF)
    {
        init();
        cout<<"Expression: ";
        for(int i=1;i<maxn;ch=getc(stdin))
        {
            if(ch=='\n' || ch==EOF){s[i]='\0';break;}
            if(ch!=' '){s[i]=ch;i++;}
            cout<<ch;
        }
        cout<<endl;
        s[0]='a';int len=strlen(s);s[0]='\0';
        cout<<"    value = "<<evaluating(len-1,s+1)<<endl;
        for(int i=0;i<26;i++)
            if(value[i][1]==1)cout<<"    "<<(char)(i+'a')<<" = "<<value[i][0]<<endl;
    }
    return 0;

}
//左结合 右结合~
