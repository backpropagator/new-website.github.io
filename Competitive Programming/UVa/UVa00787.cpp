#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	ll a;
	while(scanf("%lld",&a)){
		vector<ll> num;
		num.push_back(a);
		while(cin>>a && a != -999999){
			num.push_back(a);
		}
		ll loc_max = num[0], loc_min = num[0], glob_max = num[0];
		for (int i = 1; i < num.size(); ++i)
		{
			ll cur = loc_max;
			loc_max = max({num[i],num[i]*cur,num[i]*loc_min});
			loc_min = min({num[i],num[i]*cur,num[i]*loc_min});
			glob_max = max({glob_max,loc_max,loc_min});
		}
		//ll ans = max(loc_max,glob_max);
		cout<<glob_max<<"\n";
	}
	return 0;
}