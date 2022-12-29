#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int tc;
	ll n, t = 1;
	cin>>tc;
	while(tc--){
		cin>>n;
		ll p[n-1];
		for (int i = 0; i < n-1; ++i)
		{
			cin>>p[i];
		}
		ll sum = 0, ans = 0, f = 0, l = 0; 
		for (int i = 0; i < n-1; ++i)
		{
			sum += p[i];
			ans = max(ans,sum);
			if(sum < 0){
				sum = 0;
				f = i;
				l = i;
			}else{
				l++;
			}
		}
		if(sum > 0){
			printf("The nicest part of route %lld is between stops %lld and %lld\n", t, f, l);

		}else{
			printf("Route %lld has no nice parts\n", t);
		}
		t++;
	}
}