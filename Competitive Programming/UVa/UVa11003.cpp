#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N;
vector<ll> wt, load;
ll dp[1005][3005];

ll solve(ll idx, ll rem){
	if(idx == N || rem == 0){
		dp[idx][rem] = 0;
		return 0;
	}
	if(dp[idx][rem] != -1){
		return dp[idx][rem];
	}
	ll ans;
	if(wt[idx] <= rem){
		ans = max(solve(idx+1,rem),solve(idx+1,min(rem-wt[idx],load[idx]))+1);
	}else{
		ans = solve(idx+1,rem);
	}
	return dp[idx][rem] = ans;
}

int main(){
	ll w, l;
	while(cin>>N && N){
		memset(dp,-1,sizeof dp);
		for (int i = 0; i < N; ++i)
		{
			cin>>w>>l;
			wt.push_back(w);
			load.push_back(l);
		}
		ll ans = 1;
		for (int i = 0; i < N; ++i)
		{
			ans = max(ans,solve(i+1,load[i])+1);
		} 
		cout<<ans<<"\n";
		wt.clear();
		load.clear();
	}
}
