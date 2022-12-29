#include <bits/stdc++.h>
typedef int64_t ll;
using namespace std;
int64_t n, m, k, cnt;
ll dp[55][55];

int64_t BC(ll n1, ll k1){
	if(n1 == n && k1 == k){
		return 1;
	}
	if(n1 > n || k1 > k){
		return 0;
	}
	if(dp[n1][k1] != -1){
		return dp[n1][k1];
	}
	ll ans = 0;
	for(ll i = 1; i <= m; i++)
		ans += BC(n1+i,k1+1);
	return dp[n1][k1] = ans;
}


int main(){
	while(cin>>n>>k>>m){
		memset(dp,-1,sizeof dp);
		cnt = 0;
		cout<<BC(0,0)<<"\n";
	}
} 