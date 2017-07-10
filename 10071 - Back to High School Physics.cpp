#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


int main()

{
    int v[2],t=0;
    memset(v,0,sizeof(v));
    for(int i=0;scanf("%d %d",&v[i%2],&t)==2;i++)
    {
        if(t==0){printf("%d\n",0);continue;}
        printf("%d\n",2*v[i%2]*t);
    }
    return 0;

}
