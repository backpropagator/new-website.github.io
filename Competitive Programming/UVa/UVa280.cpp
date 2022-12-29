#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
typedef vector<ll> vi;
typedef vector<vi> vvi;

vvi adj(104);
vector<bool> vis(104, false);
ll n;

void dfs(ll start, ll tm){
	if(tm > 0){
		vis[start] = true;
	}
	for (int i = 0; i < (int)adj[start].size(); ++i)
	{
		if(!vis[adj[start][i]]){
			dfs(adj[start][i],tm+1);
		}
	}
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin>>n && n != 0){
    	ll node, tmp;
    	adj.clear();
    	while(cin>>node && node != 0){
    		while(cin>>tmp && tmp != 0){
    			adj[node].pb(tmp);
    		}
    	}
    	ll num, start;
    	cin>>num;
    	while(num--){
    		cin>>start;
    		//vis.clear();
    		fill(vis.begin(), vis.end(), false);
    		dfs(start,0);
    		ll cnt=0;
    		vi novis;
    		for (ll i = 1; i <= n; ++i)
    		{
    			if(!vis[i]){
    				cnt++;
    				novis.pb(i);
    			}
    		}
    		cout<<cnt<<" ";
    		for (int i = 0; i < novis.size(); ++i)
    		{
    			cout<<novis[i];
    			if(i != novis.size()-1){
    				cout<<" ";
    			}
    		}
    		cout<<"\n";
    	}
    }
	
}

