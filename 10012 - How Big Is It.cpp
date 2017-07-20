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
        int m;double r[8],length=FLT_MAX,sum;
        cin>>m;
        for(int j=0;j<m;j++){cin>>r[j];}

        sort(r,r+m);
//        for(int j=0;j<m;j++)
//            cout<<r[j]<<endl;
        do{
            sum=r[0]+r[m-1];
            for(int k=0;k<m-1;k++)
                sum+=2*sqrt(r[k]*r[k+1]);//something wrong
            length = sum<length ? sum:length;
        printf("%.3lf\n",length);
        }while(next_permutation(r,r+m));
        printf("\n");

    }

    return 0;
}
