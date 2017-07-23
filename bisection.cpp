#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

void bisection(double x,double y)
{
    double m=(x+y)/2;
    double e=sqrt(m+15)+sqrt(m);
    if(e>14.99999999 && e<15.0000001)cout<<"x="<<m<<endl;
    if(e<=14.99999999){cout<<e<<endl;bisection(m,y);}
    if(e>=15.0000001){cout<<e<<endl;bisection(x,m);}
}


int main()
{
    cout<<"What is X?"<<endl;
    bisection(0,210);
//    double x=0,y=210;
//    double m=x+y/2;
//    double e=sqrt(m+15)+sqrt(m);
//    cout<<e;
    return 0;
}
