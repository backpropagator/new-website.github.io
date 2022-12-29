#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
ll n, l, r;
ll dp[200005][3];

ll bt(ll cur, ll sum){
	sum = sum%3;
	if(cur == n){
		if(sum%3 == 0) return 1;
		else return 0;
	}
	if(dp[cur][sum] != -1) return dp[cur][sum];
	ll ans = 0;
	for (int i = l; i < r+1; ++i)
	{
		ans += bt(cur+1,sum+i);
	}
	return dp[cur][sum] = ans%MOD;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof dp);
	//ll n, l, r;
	cin>>n>>l>>r;
	cout<<bt(0,0)<<"\n";

}

