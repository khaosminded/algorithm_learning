#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5000,maxc=200;
char dic[maxn][maxc];
char line[maxc];
//记一蛤
int cmp_char(const void* _a,const void* _b)
{
    char* a=(char*) _a;
    char* b=(char*) _b;
    return *a-*b;
}
int cmp_string(const void* _a,const void* _b)
{
    char* a=(char*) _a;
    char* b=(char*) _b;
    return strcmp(a,b);
}
void filter(char * l)
{
    for(int i=0;l[i]!='\0';i++)
        if(!(97<=l[i]&&l[i]<=122))
            for(int j=i--;l[j]!='\0';j++)
                l[j]=l[j+1];
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int c=0;
    char ch;
    while(ch!=EOF)
    {
        for(int i=0;;)
        {//读个字 转小写 有可能为空
            ch=getchar();
            ch=tolower(ch);
            if(97<=ch&&ch<=122)line[i++]=ch;
            else {line[i]=0;break;}
        }
        int i;
        for(i=0;i<c;i++) if(!strcmp(line,dic[i])) break;
        if(i==c) strcpy(dic[c++],line);

    }
    qsort(dic,c,sizeof(dic[0]),cmp_string);
    for(int i=0;i<c;i++)
        if(dic[i][0])printf("%s\n",dic[i]);//有个空串去掉
    return 0;

}
