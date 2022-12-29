#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[200005][4];
ll mins[200005];
ll n;

ll recurse(ll ind, ll rest){
	if(rest == 3){
		return INT_MAX;
	}
	if(ind == n){
		return 0;
	}
	if(dp[ind][rest] != -1){
		return dp[ind][rest];
	}
	ll ans = min(mins[ind]+recurse(ind+1,0),recurse(ind+1,rest+1));
	return dp[ind][rest] = ans;
}

int main(){
	//ll n;
	cin>>n;
	memset(dp,-1,sizeof dp);
	for (int i = 0; i < n; ++i)
	{
		cin>>mins[i];
	}
	cout<<recurse(0,0)<<"\n";
}