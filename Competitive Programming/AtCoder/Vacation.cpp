#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;

ll N;
vector<ll> a, b, c;
ll memo[100005][4];

ll dp(ll idx, ll cur, ll prev){
    if(idx == N){
        return memo[idx][prev]=0;
    }
    if(memo[idx][prev] != -1){
        return memo[idx][prev];
    }
    ll ans = 0;
    if(prev == 0){
        ans = max(dp(idx+1,b[idx+1],1),dp(idx+1,c[idx+1],2));
    }else if(prev == 1){
        ans = max(dp(idx+1,a[idx+1],0),dp(idx+1,c[idx+1],2));
    }else if(prev == 2){
        ans = max(dp(idx+1,a[idx+1],0),dp(idx+1,b[idx+1],1));
    }
    //cout<<ans<<"\n";
    memo[idx][prev] = cur+ans;
    //cout<<memo[idx]<<"\n";
    return memo[idx][prev];
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(memo, -1, sizeof memo);

    cin>>N;
    ll d, e, f;
    for (int i = 0; i < N; ++i)
    {
        cin>>d>>e>>f;
        a.pb(d), b.pb(e), c.pb(f);
    }
    ll q1 = dp(0,a[0],0), q2 = dp(0,b[0],1), q3 = dp(0,c[0],2);
    //cout<<q1<<" "<<q2<<" "<<q3<<"\n";
    cout<<max(q1,max(q2,q3));

}