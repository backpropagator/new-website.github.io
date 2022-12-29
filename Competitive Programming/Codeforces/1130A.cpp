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
	ll ne;
	cin>>ne;
	ll v[ne];
	ll p=0, n=0, z=0;
	for (int i = 0; i < ne; ++i)
	{
		cin>>v[i];
		if(v[i]>0) p++;
		else if(v[i]<0) n++;
		else z++;
	}
	//cout<<p<<" "<<n<<" "<<z<<" "<<ceil((double)ne/2.00)<<"\n";
	if(p < ceil((double)ne/2.00) && n < ceil((double)ne/2.00)) cout<<0<<"\n";
	//cout<<p<<" "<<n<<" "<<z<<" "<<ceil(ne/2)<<"\n";
	else{
		if(p >= n) cout<<1<<"\n";
		else cout<<-1<<"\n"; 
	}
}