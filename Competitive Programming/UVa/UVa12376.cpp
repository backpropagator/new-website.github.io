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
vector<vector<ll>> adj(105);
ll wt[105];
bool vis[105];

pair<ll,ll> dfs(ll x, ll cnt){
	vis[x] = true;
	ll mx = 0, nxt;
	if(adj[x].size() == 0){
		return make_pair(x,cnt);
	}
	for (int i = 0; i < adj[x].size(); ++i)
	{
		if(wt[adj[x][i]] >= mx && !vis[adj[x][i]]){
			mx = wt[adj[x][i]];
			nxt = adj[x][i];
		}
	}
	return dfs(nxt,cnt+mx);
}


int main(){
	//cout.precision(12);
	ll t, n;
	//string s;
	cin>>t;
	for (int k = 1; k <= t; ++k)
	{
		memset(vis,false,sizeof vis);
		memset(wt,0,sizeof wt);
		for (int i = 0; i < 105; ++i) adj[i].clear();
		ll n, m, w;
		cin>>n>>m;
		for (int i = 0; i < n; ++i)
		{
			cin>>wt[i];
		}
		ll x, y;
		for (int i = 0; i < m; ++i)
		{
			cin>>x>>y;
			adj[x].pb(y);
		}
		pair<ll,ll> ans = dfs(0,0);
		cout<<"Case "<<k<<": "<<ans.second<<" "<<ans.first<<"\n";
	}

}