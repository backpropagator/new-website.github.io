#include <bits/stdc++.h>
#define MAX 1000007
typedef long long ll;
using namespace std;

int main(){
	int prime[] = {2,3,5,7};
	int nprime[] = {4,6,8,9};
	ll dp[MAX] = {0};
	for (int i = 0; i < 4; ++i)
	{
		dp[nprime[i]] = 2;
		dp[prime[i]] = 1;
	}
	dp[0] = -1, dp[1] = -1;
	for (ll i = 10; i < MAX; ++i)
	{
		dp[i] = 1 + dp[i-7];
	}
	ll tc, x;
	cin>>tc;
	while(tc--){
		cin>>x;
		cout<<dp[x]<<"\n";
	}
}