#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int n,f,line[3];
    scanf("%d",&n);
    for(int i=0;i<n&&(1==scanf("%d",&f));i++)
    {
        int summed=0;
        for(int j=0;j<f && (3==scanf("%d %d %d",&line[0],&line[1],&line[2]));j++)
            summed+=line[0]*line[2];
        printf("%d\n",summed);

    }
    return 0;

}
