#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
double change[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[30005][13];

ll cc(ll c, int idx){
	if(idx > 10){
		return 0;
	}
	if(c == 0){
		dp[c][idx] = 1;
		return 1;
	}
	if(c < 0){
		return 0;
	}
	if(dp[c][idx] != -1){
		return dp[c][idx];
	}
	ll ans = cc(c,idx+1)+cc(c-change[idx],idx);
	return dp[c][idx] = ans;
}

int main(){
	double c;
	while(cin>>c && c!=0.00){
		memset(dp,-1,sizeof dp);
		//c = c*10;
		ll k = c*100;
		//cout<<k;
		ll ans = cc(k,0);
		printf("%6.2lf%17.lld\n", c, ans);
	}

}