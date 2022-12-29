#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
vector<vector<ll>> adj(100005);
ll n;
ll v[55][55], e[55][55];
set<pair<ll,ll>> s1, s2;

void dfs(ll r, ll c, ll k){
	e[r][c] = 1;
	if(k == 1) s1.insert(make_pair(r,c));
	else s2.insert(make_pair(r,c));
	
	if(!e[r-1][c] && !v[r-1][c] && r-1 >= 0) dfs(r-1,c,k);
	if(!e[r+1][c] && !v[r+1][c] && r+1 < n) dfs(r+1,c,k);
	if(!e[r][c-1] && !v[r][c-1] && c-1 >= 0) dfs(r,c-1,k);
	if(!e[r][c+1] && !v[r][c+1] && c+1 < n) dfs(r,c+1,k);

}

int main(){
	//ll n;
	cin>>n;
	ll r1, c1, r2, c2;
	cin>>r1>>c1>>r2>>c2;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		for (int j = 0; j < s.length(); ++j)
		{
			if(s[j]=='0') v[i][j]=0;
			if(s[j]=='1') v[i][j]=1;
			//cin>>v[i][j];
		}
	}
	memset(e, 0, sizeof e);
	dfs(r1-1,c1-1,1);
	memset(e, 0, sizeof e);
	dfs(r2-1,c2-1,2);
	ll ans = INT_MAX;
	if(s1 == s2) cout<<0<<"\n";
	else{
		set<pair<ll,ll>>::iterator it1, it2;
		for(it1 = s1.begin(); it1 != s1.end(); it1++){
			for(it2 = s2.begin(); it2 != s2.end(); it2++){
				ll a1 = (*it1).first, b1 = (*it1).second, a2 = (*it2).first, b2 = (*it2).second;
				ll tmp = (ll)(pow(a2-a1,2) + pow(b2-b1,2));
				ans = min(ans,tmp);
			}
		} 
		cout<<ans<<"\n";
	}

}