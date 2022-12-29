#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, a, b, c, m;
ll memo[4005];

ll dp(ll cur){
	if(cur < 0){
		return -100000000;
	}
	if(cur == 0)
		return 0;
	/*if(cur < m){
		return 1;
	}*/
	if(memo[cur] != -1){
		return memo[cur];
	}
	//ll v1, v2, v3;
	//v1 =
	ll ans = 1 + max(dp(cur-a), max(dp(cur-b),dp(cur-c)));
	return memo[cur] = ans; 
}


int main(){
	ios_base::sync_with_stdio(false);
	memset(memo, -1, sizeof memo);
	cin>>n>>a>>b>>c;
	m = min(a,min(b,c));
	cout<<dp(n)<<"\n";
}