#include <bits/stdc++.h>
#define Max 1000*1000*1000 + 7
#define S 100*1000 + 11
typedef long long ll;
using namespace std;
ll n, k, x;
ll arr[S];
ll memo[S];

ll dp(ll pos){
	if(pos == n-1 ){
		if(arr[pos] != arr[pos-1]){
			for(int i=0; i<n; i++){
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
			return 1;
		}else{
			return 0;
		}
	}
	//if(memo[pos] != -1)
	//	return memo[pos];
	ll ans = 0;
	for(ll i=1; i<=k; i++){
		if(i != arr[pos-1]){
			arr[pos] = i;
			ans += dp(pos+1);
		}
	}
	return memo[pos] = ans;
}


int main(){
	cin>>n>>k>>x;
	memset(memo, -1, sizeof memo);
	arr[0] = 1, arr[n-1] = x;
	cout<<dp(1)<<"\n";
}