#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t, n;
ll memo[2][100007];
vector<ll> track1, track2, toll1, toll2;


ll dp(ll i, ll current){
	if(i == 0){
		if(current == 0){
			return track1[i];
		}else{
			return track2[i];
		}
	}

	if(memo[current][i] != -1){
		return memo[current][i];
	}
	ll v1, v2;
	if(current == 0){
		v1 = toll2[i-1] + track1[i] + dp(i-1,1-current);
		v2 = dp(i-1,current) + track1[i];
		return memo[current][i] = min(v1,v2);
	}
	else if(current == 1){
		v1 = toll1[i-1] + track2[i] + dp(i-1,1-current);
		v2 = dp(i-1,current) + track2[i];
		return memo[current][i] = min(v1,v2);
	}

}


int main(){
	ll a;
	cin>>t;
	while(t--){
		memset(memo, -1, sizeof memo);
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>a;
			track1.push_back(a);
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>a;
			track2.push_back(a);
		}
		for (int i = 0; i < n-1; ++i)
		{
			cin>>a;
			toll1.push_back(a);
		}
		for (int i = 0; i < n-1; ++i)
		{
			cin>>a;
			toll2.push_back(a);
		}
		cout<<min(dp(n-1,0),dp(n-1,1))<<"\n";
		track1.clear();
		track2.clear();
		toll1.clear();
		toll2.clear();
	}

}