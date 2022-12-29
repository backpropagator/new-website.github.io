#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int t;
	cin>>t;
	ll n, k;
	while(t--){
		cin>>n>>k;
		ll arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		ll sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if(i%2 == 0){
				if(abs(sum+arr[i]-k) <= abs(sum-arr[i]+k)){
					sum = sum + arr[i];
				}else{
					sum = sum - arr[i];
				}

			}else{
				if(abs(sum+arr[i]-k) <= abs(sum-arr[i]+k)){
					sum = sum - arr[i];
				}else{
					sum = sum + arr[i];
				}
			}
		}
		if(abs(sum) >= k){
			cout<<1<<"\n";
		}else{
			cout<<2<<"\n";
		}
	}
}