#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;

ll N, W;
vector<ll> w, v; 
ll dp[100005][105];

ll bt(ll rem,  ll idx){
    if(rem < 0){
        return -1*INT_MAX;
    }
    if(rem == 0){
        return dp[rem][idx] = 0; 
    }

    if(idx == N ){
        return dp[rem][idx] = 0; 
    }
    if(dp[rem][idx] != -1){
        return dp[rem][idx];
    }

    ll ans  = 0;

    if(w[idx] > rem){
        ans = bt(rem, idx+1);
    }
    else{
        ans = max(v[idx]+bt(rem-w[idx],  idx+1), bt(rem, idx+1));
    }

    dp[rem][idx] = ans;
    return dp[rem][idx];
}

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin>>N>>W;
    ll t1, t2;
    for (int i = 0; i < N; ++i)
    {
        cin>>t1>>t2;
        w.pb(t1), v.pb(t2);
    }
    ll a1 = bt(W,0);
    cout<<a1<<"\n";

}