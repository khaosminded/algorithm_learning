#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;




int evolution_rules(int a1,int a2,int a3,int m)
{
    int a=a1*4+a2*2+a3*1;
    return m&(1<<a)? 1:0;
}
bool eq(int n,int * s,int * _a)
{
    for(int i=0;i<n;i++)
        if(s[i]!=_a[i])return false;
    return true;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n,s[32]={0};
    while(2==scanf("%d %d ",&m,&n))
    {
        for(int i=0;i<n;i++){cin>>(char&)s[i];s[i]-='0';}

        int ok=0;
        for(long i=0;i<((1<<n)-1);i++)
        {//ö��nλ
            int a[32],_a[32];//ö�ٳ�����a �;����Զ����任֮���_a
            for(int j=0;j<n;j++)
                a[j]=i&(1<<j)? 1:0;
            for(int j=0;j<n;j++)
                _a[j]=evolution_rules(a[(j+n-1)%n],a[j],a[(j+n+1)%n],m);

            //for(int j=0;j<8;j++)cout<<_a[j];cout<<endl;
            if(eq(n,s,_a)){ok=1;break;}//�����һ���任���_a��Ŀ��״̬��� ��ɵ���
        }
        printf(ok?"REACHABLE\n":"GARDEN OF EDEN\n");
    }

}
//Ŷ�� ��һ����   XOR �Ĺ��򰡣����Ǹ��˸���ֵ��
//Ŷ��2 ����Ϊn ö�ٵ�λ�����̶�
