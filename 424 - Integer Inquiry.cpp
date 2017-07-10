#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
const int maxn=3000;
struct bign
{
    int len,s[maxn];
    bign(){memset(s,0,sizeof(s));len=1;}

    bign operator = (const char* num)
    {
        len=strlen(num);
        for(int i=0;i<len;i++)s[i]=num[len-i-1]-'0';
        return *this;
    }

    bign operator = (int num)
    {
        char s[maxn];
        sprintf(s,"%d",num);
        *this = s;//operator = (const char* num)
        return *this;
    }

    bign(int num){*this=num;}
    bign(const char* num){*this=num;}

    string str()const
    {
        string res ="";
        for(int i=0;i<len;i++) res = (char)(s[i]+'0')+res;
        if(res=="") res = "0";
        return res;
    }

    bign operator + (const bign &b) const
    {
        bign c;
        c.len=0;
        for(int i=0,g=0;g||max(len,b.len)>i;i++)
        {
//            int buffer=g;
//            if(i<len)buffer+=s[i];
//            if(i<b.len)buffer+=b.s[i];

            int x=s[i]+b.s[i]+g;
            c.s[c.len++]=x%10;
            g=x/10;
        }
        return c;
    }
    bign operator += (const bign &b)
    {
        *this=*this + b;
        return *this;
    }

    bign operator * (const bign &b)const
    {
        bign c;
        for(int i=0;i<b.len;i++)
        {
            bign buf;
            for(int j=0,g=0;g/*默认高位为零*/||j<len;j++)
            {
                //a全部乘以b的一位
                int x;
                x = s[j]*b.s[i]+g;
                g = x/10;
                buf.s[i+j] = x%10;
                buf.len=i+j+1;
            }
            c+=buf;
        }
        return c;
    }


    bool operator <(const bign &b)const
    {
        if(len!=b.len)return len<b.len;
        for(int i=len-1;i>=0;i++)
            if(s[i]!=b.s[i]) return s[i]<b.s[i];
        return false;
    }
    bool operator > (const bign &b)const{return b<*this;}
    bool operator == (const bign &b)const{return !(b<*this||*this<b);}
    bool operator >= (const bign &b)const{return !(b<*this);}
    bool operator <= (const bign &b)const{return!(*this<b);}
    bool operator != (const bign &b)const {return b<*this||*this<b;}

    bign operator - (const bign &b)const
    {//非负
        bign c;
        if(*this<b){return c;}
        for(int i=0,g=0;i<len;i++)
        {
            int x;
            x=s[i]-b.s[i]-g;
            c.s[i] = x>=0 ? x : x+10;
            c.len=i+1;
            g = x>=0 ? 0 : 1;
        }
        for(int i=c.len-1;i>=1;i--){if(c.s[i])break;c.len--;}
        return c;

    }
};
istream& operator >>(istream& in, bign &x)
{
    string s;
    in>>s;//默认输入流只有0~9
    x=s.c_str();
    return in;
}
ostream& operator <<(ostream& out,const bign &x)
{
    out<<x.str();
    return out;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char ch[maxn];
    bign a;
    bign b;
    for(;;)
    {
        scanf("%s",ch);if('0'==ch[0])break;
        b=ch;a+=b;
    }
    cout<<a<<endl;//记得来个回车
    return 0;
}
