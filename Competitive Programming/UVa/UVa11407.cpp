#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N;
ll dp[10005];

ll square(ll cur){
	if(cur == N){
		return 0;
	}
	if(cur > N){
		return 0;
	}
	if(dp[cur] != -1){
		return dp[cur];
	}
	ll ans = INT_MAX;
	for(ll i = 1; i*i <= N; i++){
		ans = min(ans, 1 + square(cur + (i*i)));
	}
	return dp[cur] = ans;
}


int main(){
	ll tc;
	cin>>tc;
	while(tc--){
		memset(dp,-1,sizeof dp);
		cin>>N;
		cout<<square(0)<<"\n";
	}
}