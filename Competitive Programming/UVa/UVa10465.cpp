#include <bits/stdc++.h>
#define S 10003
using namespace std;

int M, N, mn, mm, nn, P;
int dp[S];

int HomerSimpson(int t){
    if(t <= 0){
        if(!t)return 0;
        mn = min(mn, P);
        return -S;
    }
    if(dp[t] != 0)return dp[t];
    P = t;
    dp[t] = max(HomerSimpson(t-M)+1, HomerSimpson(t-N)+1);
    return dp[t];
}

int HomerSimp(int t){
    if(!t)return 0;
    if(t < 0)return -S;
    if(dp[t] != -1)return dp[t];
    dp[t] = max(HomerSimp(t-M)+1, HomerSimp(t-N)+1);
    return dp[t];
}

int main(){
    int ans, T;
    while(cin >> M >> N >> T){
        memset(dp, 0, sizeof(dp)), mn = S;
        if(T < M && T < N){
            cout << "0 "  << T << endl;
            continue;
        }
        ans = HomerSimpson(T);
        if(ans > 0)cout << ans << endl;
        else{
            memset(dp, -1, sizeof(dp));
            ans = HomerSimp(T-mn);
            cout << ans << " " << mn << endl;
        }
    }
    return 0;
}