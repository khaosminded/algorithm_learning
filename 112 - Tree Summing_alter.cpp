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
//���ʶ��ʽ�˰����о��о���� ���첻���µ���2017��6��23��22:24:02
//����� ��һ��2017��6��25��16:05:23
//�����ܷ��һ�������ĺ�ѽ
//֮ǰд�Ĵ����и��������0()
//���д�Ĵ��ڰ���пռ�Ҳ�ж��ˡ�������Ŷ��-1(-1()(-1()()))
