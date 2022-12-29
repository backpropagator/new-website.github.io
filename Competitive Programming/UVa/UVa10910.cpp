#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, t, p;
ll dp[75][75];

ll F(ll T, ll N){
	if(dp[N][T] != -1){
		return dp[N][T];
	}
	if(N == 1){
		if(T >= p){
			return 1;
		}else{
			return 0;
		}
	}
	ll ans = 0;
	for(int i = p; i <= T - ((N-1)*p); i++){
		ans += F(T-i,N-1);
	}
	return dp[N][T] = ans;
}


int main(){
	ll tc;
	cin>>tc;
	while(tc--){
		cin>>n>>t>>p;
		memset(dp, -1 ,sizeof dp);
		cout<<F(t,n)<<"\n";
	}
}