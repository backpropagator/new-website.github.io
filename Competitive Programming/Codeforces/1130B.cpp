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
	ll n;
	cin>>n;
	ll v[2*n];
	map<ll,ll> freq, bm;
	map<pair<ll,ll>,ll> pr;
	for (int i = 0; i < 2*n; ++i)
	{
		cin>>v[i];
		if(freq[v[i]] == 0){
			freq[v[i]]++;
			bm[i] = 1;
			pr[make_pair(v[i],1)] = i;
		}else{
			freq[v[i]]++;
			bm[i] = 2;
			pr[make_pair(v[i],2)] = i;
		}
	}
	ll l1=0, l2=0;
	ll c1=0, c2=0;
	for (int i = 1; i <= n; ++i)
	{
		c1 += (abs(pr[make_pair(i,1)]-l1));
		l1 = pr[make_pair(i,1)];
		c2 += (abs(pr[make_pair(i,2)]-l2));
		l2 = pr[make_pair(i,2)];
	}
	cout<<c1+c2<<"\n";

}