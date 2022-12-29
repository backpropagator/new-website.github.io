#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N, K;
ll dp[105][105];

ll cal(ll sum, ll len){
	if(sum == N && len == K){
		return 1;
	}
	else if(sum > N){
		return 0;
	}
	if(len > K){
		return 0;
	}

	if(dp[sum][len] != -1){
		return dp[sum][len];
	}
	ll ans = 0;
	for(ll i = sum; i <= N; i++){
		ans += cal(sum+i,len+1);
	}
	return dp[sum][len] = ans;
}


int main(){
	while(cin>>N>>K && N+K){
		memset(dp, -1, sizeof dp);
		cout<<cal(0,0)<<"\n";
	}
}