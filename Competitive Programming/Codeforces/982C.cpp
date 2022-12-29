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
#define N 1000000
vector<ll> adj[N],sub(N,0);
vector<bool> visited(N,0);
ll ans=0;
ll DFSUtil(ll u,ll last)
{
    ll su=0;
    for (ll i=0; i<adj[u].size(); i++)
    {
        if(adj[u][i]==last)
            continue;
        ll x=DFSUtil(adj[u][i],u);
        su+=x;
        ans+=(x-1)%2;
    }
    sub[u]=su+1;
    return su+1;
}
void aE(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{

    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        aE(a,b);
    }
    DFSUtil(1,0);
    if(n%2==1)
    {
        cout<<-1;
        return 0;
    }
    cout<<ans<<endl;
}