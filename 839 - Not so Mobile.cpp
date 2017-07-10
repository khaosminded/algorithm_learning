#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//2017年6月29日20:45:47

bool solve_strict(int &n)
{
    int l,r;
    int w1,r1,w2,r2;
    bool result;
    scanf("%d %d %d %d",&w1,&r1,&w2,&r2);
    if(w1!=0 && w2!=0)
    {
        n = w1+w2;
        result = w1*r1==w2*r2;
    }
    if(w1==0 && w2==0)
    {
        result = solve_strict(l)&solve_strict(r);
        result = result & (l*r1==r*r2);
        n = l+r;
    }
    if(0==w1 && 0!=w2)
    {
        result = solve_strict(l);
        result = result & (l*r1==w2*r2);
        n = l+w2;
    }
    if(0!=w1 && 0==w2)
    {
        result = solve_strict(r);
        result = result & (w1*r1==r*r2);
        n = w1+r;
    }
    return result;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,useless;
    cin>>n;
    for(int i=0;i<n;i++)
        {cout<<(solve_strict(useless)?"YES":"NO")<<endl;if(i<n-1)cout<<endl;}
    return 0;

}
//2017年6月29日22:02:06
