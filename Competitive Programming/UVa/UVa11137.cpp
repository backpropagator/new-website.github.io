#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll cubes[21];
ll dp[10005][24];

void init(){
	for (int i = 1; i <= 21; ++i)
	{
		cubes[i-1] = i*i*i; 
	}
}

ll cc(ll c, ll idx){
	if(idx > 20){
		return 0;
	}
	if(c == 0){
		dp[c][idx]=1;
		return 1;
	}
	if(c < 0){
		return 0;
	}
	if(dp[c][idx] != -1){
		return dp[c][idx];
	}

	ll ans = cc(c,idx+1)+cc(c-cubes[idx],idx);
	return dp[c][idx] = ans;
}

int main(){
	init();
	ll n;
	while(cin>>n){
		memset(dp,-1,sizeof dp);
		cout<<cc(n,0)<<"\n";
	}
}