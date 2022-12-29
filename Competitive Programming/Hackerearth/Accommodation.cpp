#include<bits/stdc++.h>
using namespace std;

int main()
{
int m,n;
scanf("%d %d",&m,&n);
int* c = new int[m];
for(int i=0;i<m;i++)
scanf("%d",&c[i]);
long long* dp = new long long[(n+1)*(m+1)];
for(int i=0;i<=n;i++)
for(int j=0;j<=m;j++)
{
if(i==0)
dp[i*(m+1)+j] = 1;
else if(j==0)
dp[i*(m+1)+j] = 0;
else if(i-c[j-1]>=0)
dp[i*(m+1)+j] = (dp[(i-c[j-1])*(m+1)+j]+dp[i*(m+1)+(j-1)])%1000000007;
else
dp[i*(m+1)+j] = dp[i*(m+1)+(j-1)];
}
printf("%lld\n",dp[n*(m+1)+(m)]);
return 0;
}