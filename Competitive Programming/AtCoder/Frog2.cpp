#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N, K;
int dp[100005];
vector<int> pillar;
 
int jump(int now, int cost){
    if(dp[now] != -1){
        return cost + dp[now];
    }
    if(pillar.size() == now + 1){
        dp[now] = 0;
    }else if(pillar.size()-1 < now ){
        //dp[now] = abs(pillar[now] - pillar[now + 1]);
        return INT_MAX;
    }else{
        int ans = INT_MAX;
        for (int i = now+1; i <= now+K; ++i)
        {
            ans = min(ans, jump(i, abs(pillar[now] - abs(pillar[i]))));
        }
        dp[now] = ans;
    }
    return cost + dp[now];
}
 
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        pillar.push_back(input);
    }
    memset(dp, -1, sizeof dp);
    cout << jump(0, 0) << endl;
}