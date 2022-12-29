#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll memo[1000];

ll dp(ll n){
    if(n == 1){
        return 0;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    if(n%2 == 0 && n%3 == 0){
        ll ans = 1 + min(min(dp(n-1),dp(n/2)),dp(n/3));
        return memo[n] = ans;
    }
    else if(n%2 == 0 && n%3 != 0){
        ll ans = 1 + min(dp(n-1),dp(n/2));
        return memo[n] = ans;
    }
    else if(n%3 == 0 && n%2 != 0){
        ll ans = 1 + min(dp(n-1),dp(n/3));
        return memo[n] = ans;
    }
    else{
        ll ans = 1 + dp(n-1);
        return memo[n] = ans;
    }
}

int main(){
    ll n;
    memset(memo,-1,sizeof(memo));
    memo[1]=0;
    memo[0]=0;
    cin>>n;
    cout<<dp(n);
}