#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
	ll tc, n, k;
	cin>>tc;
	while(tc--){
		cin>>n>>k;
		ll stk[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>stk[i];
		}
		ll dp[n] = {0};
		if(stk[0] <= k){
			dp[0] = stk[0];
		}else{
			dp[0] = 0;
		}
		ll ans = 0;
		for (int i = 1; i < n; ++i)
		{
			if(stk[i] <= k){
				dp[i] = stk[i] + dp[i-1];
			}else{
				dp[i] = 0;
			}	
			//ans = max(ans,dp[i]);
		}
		for (ll i = 0; i < n; i++)
		{
			ans = max(ans,dp[i]);
		}
		
		cout<<ans<<"\n";
	}
}