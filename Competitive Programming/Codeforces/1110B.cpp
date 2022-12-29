#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back
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

    int n,m,k;
    cin >> n >> m >> k;
    int broken[n];
    for (int i=0;i<n;i++)
    {
        cin >> broken[i];
    }
    long long int ans=n;
    vector<int> distance;
    for (int i=1;i<n;i++)
    {
        distance.pb(broken[i]-broken[i-1]-1);
    }
    sort(distance.begin(),distance.end());
    int joins=n-k;
    for (int i=0;i<n-k;i++)
    {
        ans+=distance[i];
    }

    cout << ans << endl;

    return 0;
}

