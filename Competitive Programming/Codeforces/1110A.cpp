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

    ll b, k;
    cin>>b>>k;
    ll v[k];
    for (int i = 0; i < k; ++i)
    {
    	cin>>v[i];
    }
    int last = b%10;
    if(last%2 == 0 && v[k-1]%2 == 0){
    	cout<<"even"<<"\n";
    }
    else if(last%2 == 0 && v[k-1]%2 != 0){
    	cout<<"odd"<<"\n";
    }
    else{
    	ll e=0, o=0;
    	for (int i = 0; i < k; ++i)
    	{
    		if(v[i]%2 == 0){
    			e++;
    		}else{
    			o++;
    		}
    	}
    	if(o%2 == 0){
    		cout<<"even"<<"\n";
    	}else{
    		cout<<"odd"<<"\n";
    	}
    }
	
}

