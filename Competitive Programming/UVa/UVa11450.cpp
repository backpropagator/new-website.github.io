#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll m, c, k;
ll dp[211][25], price[25][25];

ll find_optimal(ll money, ll g){
	if(money < 0) return -100000000000;
	if(g == c) return m-money;
	if(dp[money][g] != -1) return dp[money][g];
	ll ans = -1;
	for (int i = 1; i <= price[g][0]; ++i)
	{
		//ll ans = -1;
		ans = max(ans,find_optimal(money-price[g][i],g+1));
	}
	return dp[money][g] = ans;
}


int main(){
	ll tc;
	cin>>tc;
	while(tc--){
		cin>>m>>c;
		memset(dp,-1,sizeof dp);
		for (int i = 0; i < c; ++i)
		{
			cin>>price[i][0];
			for (int j = 1; j <= price[i][0]; j++)
			{
				cin>>price[i][j];
			}
		}
		ll ans = find_optimal(m,0);
		ans < 0 ? cout<<"no solution\n" : cout<<ans<<"\n";
	}
}