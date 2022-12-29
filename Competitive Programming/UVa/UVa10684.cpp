#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n;
	while(cin>>n && n){
		ll arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		ll sum = 0, ans = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += arr[i];
			ans = max(ans,sum);
			if(sum < 0)
				sum = 0;
		}
		if(ans <= 0){
			printf("Losing streak.\n");
		}else{
			printf("The maximum winning streak is %lld.\n", ans);
		}
	}
}