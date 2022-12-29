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
bool vis[105];

void dfs(ll u, ll cnt){
	if(cnt != 0) vis[u] = true;
	for (int i = 0; i < adj[u].size(); ++i)
	{
		if(!vis[adj[u][i]])
			dfs(adj[u][i],cnt+1);
	}
}

int main(){
	ll n;
	while(cin>>n && n){
		ll p, q;
		while(cin>>p && p){
			while(cin>>q && q){
				adj[p].push_back(q);
			}
		}
		ll t, s;
		cin>>t;
		while(t--){
			cin>>s;
			memset(vis,false,sizeof vis);
			dfs(s,0);
			vector<ll> mis;
			for (int i = 1; i <= n; ++i)
			{
				if(!vis[i]) mis.pb(i);
			}
			cout<<mis.size();
			if(mis.size() != 0){
				for (int i = 0; i < mis.size(); ++i)
				{
					cout<<" "<<mis[i];
				}
			}
			cout<<"\n";
			for (int i = 0; i < adj.size(); ++i) adj[i].clear();
		}
	}

}