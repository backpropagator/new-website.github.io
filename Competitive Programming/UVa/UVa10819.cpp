#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll m, n;
vector<ll> price, val;
ll dp[105][505];

ll knapsack(int idx, ll remW){
	if(remW == 0){
		dp[idx][remW] = 0;
		return 0;
	}
	if(idx == n){
		return 0;
	}
	if(dp[idx][remW] != -1){
		return dp[idx][remW];
	}
	if(price[idx] > remW){
		return knapsack(idx+1,remW);
	}
	ll ans;
	if(price[idx] <= remW){
		ans = max(knapsack(idx+1,remW),val[idx]+knapsack(idx+1,remW-price[idx]));
	}
	return dp[idx][remW] = ans;
}

int main(){
	ll p, v;
	while(scanf("%lld %lld",&m,&n) != EOF){
		for (int i = 0; i < n; ++i)
		{
			memset(dp,-1,sizeof(dp));
			cin>>p>>v;
			price.push_back(p);
			val.push_back(v);
		}
		if(m > 2000){
			cout<<knapsack(0,m+200)<<"\n";
		}else{
			cout<<knapsack(0,m)<<"\n";
		}
		price.clear();
		val.clear();
	}

}