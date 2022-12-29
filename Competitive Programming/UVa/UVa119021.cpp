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

vector<vi> adj(105);
bool vis[105];

void dfs(ll x){
	if(vis[x]) return;
	vis[x] = true;
	for (int i = 0; i < adj[x].size(); ++i)
	{
		if(!vis[adj[x][i]])
			dfs(adj[x][i]);
	}
}


int main(){
	cout.precision(12);
	ll t, n;
	//string s;
	cin>>t;
	for (int k = 1; k <= t; ++k)
	{
		adj.clear();
		memset(vis, false, sizeof vis);
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			ll p;
			for (int j = 0; j < n; ++j)
			{
				cin>>p;
				if(p) adj[i].pb(j);
			}
		}
		map<ll,set<ll>> dom;
		for (int i = 0; i < n; ++i)
		{
			memset(vis, false, sizeof vis);
			vis[i] = true;
			dfs(0);
			for (int j = 0; j < n; ++j)
			{
				if(!vis[j]) dom[i].insert(j);
				dom[i].insert(i);
			}
			//vis[i] = false;
		}
		memset(vis, false, sizeof vis);
		dfs(0);

		string d = "+";
		for (int i = 0; i < 2*n-1; ++i)
		{
			d += "-";
		}
		d += "+";
		cout<<"Case "<<k<<":\n";
		cout<<d<<"\n";
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if((dom[i]).count(j) && vis[j]) cout<<"|Y";
				else cout<<"|N";
			}
			cout<<"|\n";
			cout<<d<<"\n";
		}
	}

}