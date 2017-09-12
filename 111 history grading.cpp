#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=30;
int m1[N],m2[N],dp[N][N];
void dP(int n)
{
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(m1[i]==m2[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
			}
		}
	}
	cout<<dp[n][n]<<endl;
}
int main()
{
	int n;
	cin>>n;
	int a,i,j;
	for(i=1;i<=n;i++){
		cin>>a;
		m1[a]=i;
	}
	while(scanf("%d",&a)==1){
		m2[a]=1;
		memset(dp,0,sizeof(dp));
		for(j=2;j<=n;j++){
			cin>>a;
			m2[a]=j;
		}
		dP(n);
	}
	return 0;
}
// µ¹Ò»ÏÂË³Ðò f(x)=y => f(y)=x
