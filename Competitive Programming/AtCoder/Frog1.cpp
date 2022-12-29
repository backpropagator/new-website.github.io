#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int dp[100000];
vector<int> pillar;
 
int jump(int now, int cost){
    if(dp[now] != -1){
        return cost + dp[now];
    }
    if(pillar.size() == now + 1){
        dp[now] = 0;
    }else if(pillar.size() == now + 2){
        dp[now] = abs(pillar[now] - pillar[now + 1]);
    }else{
        dp[now] = min(jump(now + 1, abs(pillar[now] - pillar[now + 1])), jump(now + 2, abs(pillar[now] - pillar[now + 2])));
    }
    return cost + dp[now];
}
 
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        pillar.push_back(input);
    }
    for(int i = 0; i < 100000; i++){
        dp[i] = -1;
    }
    cout << jump(0, 0) << endl;
}