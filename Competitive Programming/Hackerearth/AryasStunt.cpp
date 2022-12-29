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
vector<ll> sold(100005);

void dfs(ll u){
	vis[u] = true;
	
	for (int i = 0; i < adj[u].size(); ++i)
	{
		if(!vis[adj[u][i]]) dfs(adj[u][i]);
	}
}

int main(){
	ll n, m, p;
	cin>>n>>m;
	ll sum=0;
	ll a, b;
	for (int i = 1; i <= n; ++i)
	{
		cin>>p;
		sum += p;
		sold[i]=p;
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		if(adj[i].size() == 0){
			//cout<<"\n"<<i<<"\n";
			adj[i].pb(i);
		}
	}
	memset(vis, false, sizeof vis);
	vector<ll> par;
	ll con=0;
	for (int i = 1; i <= n; ++i)
	{
		if(!vis[i]){
			con++;
			par.pb(i);
			dfs(i);
		}
	}
	//cout<<con<<"\n";
	memset(vis, false, sizeof vis);
	ll d=0, ij=0, d1=0;
	vector<ll> burnd;
	for (int j = 1; j <= con; ++j)
	{
		dfs(par[j-1]);
		ll tmp=0;
		bool t=false;
		for (ll i = 1; i <= n; ++i)
		{
			if(vis[i]){

				//ij += sold[i];
				//d = max(d,sold[i]);
				if(sold[i] >= d){
					//d = sold[i];
					//tmp = i;
					if(sold[i] == d && tmp != 0){
						tmp = min(tmp,i);
					}else{
						tmp=i;
					}
					d = sold[i];
				}

			}
		}
		//ij -= d;
		memset(vis, false, sizeof vis);
		d1 += d;
		burnd.pb(tmp);
		d=0;
	}
	ij = sum - d1;
	sort(burnd.begin(), burnd.end());
	cout<<d1<<" "<<ij<<"\n";
	for (int i = 0; i < burnd.size(); ++i)
	{
		cout<<burnd[i]<<" ";
	}
	cout<<"\n";
}