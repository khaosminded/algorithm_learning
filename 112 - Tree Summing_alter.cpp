#include <stdio.h>
#include <iostream>
using namespace std;
bool no_root;
bool build(const int &d,int sum)
{
    int v;bool yes_o_no;
    cin>>(char&)v;//skip over left-parenthesis
    cin>>v;
    if(!cin.fail())//a node!
    {
        no_root=false;
        sum+=v;
        yes_o_no = build(d,sum)|build(d,sum);//right child |left child
    }
    else{yes_o_no = (d==sum);}//is leaf
    cin.clear();
    cin>>(char&)v;//skip over right-parenthesis
    if(no_root)return false;//empty
    return yes_o_no;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int d;
    while(cin>>d)
        {no_root=true;cout<<(build(d,0)? "yes" : "no")<<endl;}
    return 0;
}
//这个识别方式菜啊，研究研究别的 今天不做新的了2017年6月23日22:24:02
//差不多了 下一个2017年6月25日16:05:23
//还是能封进一个函数的吼呀
//之前写的错在有个特殊情况0()
//这个写的错在半道有空集也判断了。。。。哦淦-1(-1()(-1()()))
