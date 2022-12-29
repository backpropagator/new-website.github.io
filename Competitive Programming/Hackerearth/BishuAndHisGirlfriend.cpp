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
vector<vector<ll>> adj(1005);
bool vis[1005];
map<ll,pair<ll,ll>> dist;
map<ll,bool> pres;

void dfs(ll u, ll cnt){
	vis[u] = true;
	//cout<<u<<"\n";
	if(pres[u]){
	 	dist[u].second = cnt;
	 	//cout<<u<<" "<<cnt<<"\n";
	}
	for (int i = 0; i < adj[u].size(); ++i)
	{
		if(!vis[adj[u][i]]) dfs(adj[u][i],cnt+1);
	}
}

int main(){
	ll n;
	cin>>n;
	ll u, v;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll t;
	cin>>t;
	for (int i = 1; i <= t; ++i)
	{
		cin>>u;
		dist[u].first=i;
		pres[u]=true;
	}
	dfs(1,0);
	map<ll,pair<ll,ll>>::iterator itr;
	ll ans=INT_MAX, id = INT_MAX;
	for (itr = dist.begin(); itr != dist.end(); itr++)
	{
		if((itr->second).second <= ans){
			if((itr->second).second < ans) ans = (itr->second).second, id = (itr->first);
			else if((itr->second).second == ans){
				if((itr->first) < id){
					ans = (itr->second).second;
					id = (itr->first);
				}
			}
		}
	}
	cout<<id<<"\n";

}