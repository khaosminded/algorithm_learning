#include <stdio.h>
#include <iostream>
using namespace std;
bool build(const int &d,int sum,bool &pNULL)
{
    int v;bool yes_o_no=false;bool lNULL=false,rNULL=false;
    cin>>(char&)v;//skip over left-parenthesis
    cin>>v;
    if(!(pNULL=cin.fail()))//a node!
    {
        sum+=v;
        yes_o_no = build(d,sum,lNULL)|build(d,sum,rNULL);//right child |left child
        if(lNULL&&rNULL)yes_o_no=(d==sum);
    }
    cin.clear();
    cin>>(char&)v;//skip over right-parenthesis
    return yes_o_no;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int d;bool pNULL;
    while(cin>>d)
        cout<<(build(d,0,pNULL)? "yes" : "no")<<endl;
    return 0;
}

