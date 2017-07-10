#include<stdio.h>

const int maxm=51,maxn=51,maxdir=8;
char grid[maxm][maxn];
char word[maxm];

int next(int q,int p, int m, int n,int w_ptr, int dir)
{
    if('\0'==word[w_ptr])return 1;
    if((q<0)|| (p<0) || (q==m) || (p==n))return 0;
    if((word[w_ptr]==grid[q][p]+32)||(word[w_ptr]==grid[q][p]-32)||(word[w_ptr]==grid[q][p]))//ignore upper||lower
    {
//        123
//        804
//        765
        switch(dir)
        {
        case 1:
            if(next(q-1  ,p-1  ,m,n,w_ptr+1,1))return 1;break;
        case 2:
            if(next(q-1  ,p    ,m,n,w_ptr+1,2))return 1;break;
        case 3:
            if(next(q-1  ,p+1  ,m,n,w_ptr+1,3))return 1;break;
        case 4:
            if(next(q    ,p+1  ,m,n,w_ptr+1,4))return 1;break;
        case 5:
            if(next(q+1  ,p+1  ,m,n,w_ptr+1,5))return 1;break;
        case 6:
            if(next(q+1  ,p    ,m,n,w_ptr+1,6))return 1;break;
        case 7:
            if(next(q+1  ,p-1  ,m,n,w_ptr+1,7))return 1;break;
        case 8:
            if(next(q    ,p-1  ,m,n,w_ptr+1,8))return 1;break;
        }
    }
    return 0;
}

int is_here(int q,int p,int m,int n)
{
    //dir*8
    for(int i=1;i<=maxdir;i++)
        if(next(q,p,m,n,0,i))return 1;
    return 0;
}

int main()
{
//    freopen("input2.txt","r",stdin);
//    freopen("output2.txt","w",stdout);QAQ o gan jide zhushi chongdingxiang WA*6
    int m,n,x,k;
    scanf("%d",&x);
    for(int i=0;i<x&&(2==scanf("%d %d",&m,&n));i++)
    {
        for(int j=0;j<m;j++)
            scanf("%s",grid[j]);
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%s",word);
            //data received

            int ok=0;
            for(int q=0;q<m&&ok==0;q++)
                for(int p=0;p<n&&ok==0;p++)
                    if(is_here(q,p,m,n)){printf("%d %d\n",q+1,p+1);ok=1;}
        }
        if(i<x-1)printf("\n");
    }
    return 0;
}
