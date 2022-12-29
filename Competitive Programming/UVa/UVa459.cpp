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
vector<vi> adj(26);
bool vis[26];
ll n;

void dfs(ll x){
	vis[x] = true;
	for (int i = 0; i < adj[x].size(); ++i)
	{
		if(!vis[adj[x][i]]) dfs(adj[x][i]);
	}
}

int main(){
	cout.precision(12);
	ll t, n;
	//string s;
	cin>>t;
	for (int k = 1; k <= t; ++k)
	{
		for (int i = 0; i < 26; ++i) adj[i].clear();
		memset(vis,false, sizeof vis);
		char c;
		cin>>c;
		n = c-'A'+1;
		cin.ignore();
		string s;
		while(getline(cin,s) && s != ""){
			adj[s[0]-'A'].pb(s[1]-'A');
			adj[s[1]-'A'].pb(s[0]-'A');
		}
		ll ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if(!vis[i]){
				ans++;
				dfs(i);
			}
		}
		cout<<ans<<"\n";
		if(k != t) cout<<"\n";
	}

}