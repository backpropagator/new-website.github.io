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
map<ll,char> node;
vector<vector<ll>> adj(100005);
bool vis[100005];
map<char,ll> freq1, freq2;

void dfs(ll u){
	vis[u] = true;
	cout<<u<<" "<<node[u]<<"\n";
	freq1[node[u]]++;
	for (int i = 0; i < adj[u].size(); ++i)
	{
		if(!vis[adj[u][i]]) dfs(adj[u][i]);
	}
}

int main(){
	ll n, t;
	cin>>n>>t;
	char c;
	for (int i = 1; i <= n; ++i)
	{
		cin>>c;
		node[i]=c;
	}
	ll p, q;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>p>>q;
		adj[p].pb(q);
		adj[q].pb(p);
	}
	string s;
	while(t--){
		cin>>p>>s;
		memset(vis,false,sizeof vis);
		for (int i = 0; i < s.length(); ++i)
		{
			freq2[s[i]]++;
		}
		dfs(p);
		ll cnt=0;
		for(map<char,ll>::iterator itr = freq2.begin(); itr!=freq2.end(); itr++){
			ll t2 = itr->second, t1 = freq1[itr->first];
			if(t2>t1) cnt += (t2-t1);
		}
		cout<<cnt<<"\n";
	}
}