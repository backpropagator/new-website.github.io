#include <bits/stdc++.h>
typedef long long ll; 
using namespace std;
ll n;
int change[] = {1,5,10,25,50};
//vector<ll> coin;
ll dp[6][30002];

ll count(int idx, ll c){
	if(idx == 5){
		return 0;
	}

	if(c == 0){
		dp[idx][c] = 1;
		return 1;
	}

	if(c < 0){
		return 0;
	}

	if(dp[idx][c] != -1){
		return dp[idx][c];
	}

	ll ans = count(idx+1,c) + count(idx,c-change[idx]);

	return dp[idx][c] = ans;
}

int main(){
	ll a;
	while(scanf("%lld",&n) != EOF){
		memset(dp,-1,sizeof dp);
		ll ans = count(0,n);
		if(ans == 1){
			printf("There is only 1 way to produce %lld cents change.\n", n);
		}else{
			printf("There are %lld ways to produce %lld cents change.\n", ans, n);
		}

	}

}