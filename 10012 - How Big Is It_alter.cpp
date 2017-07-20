#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>
#include <float.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;double r[8],length=DBL_MAX;
        cin>>m;
        for(int j=0;j<m;j++){cin>>r[j];}
        sort(r,r+m);

        do{
            double d[8]={0};//d[]圆心横坐标 设第一个为0;
            for(int k=1;k<m;k++)
                for(int q=0;q<k;q++)
                    d[k] = 2*sqrt(r[k]*r[q])+d[q] > d[k] ? 2*sqrt(r[k]*r[q])+d[q] : d[k];
//            找 Max d[i]+r[i] Min d[i]-r[i]
            double maxr=d[0]+r[0],minl=d[0]-r[0];
            for(int k=0;k<m;k++)
            {
                maxr = d[k]+r[k]>maxr ? d[k]+r[k] : maxr;
                minl = d[k]-r[k]<minl ? d[k]-r[k] : minl;
            }
            length= maxr-minl<length ? maxr-minl : length;
        }while(next_permutation(r,r+m));
        printf("%.3lf\n",length);
    }
    return 0;
}
