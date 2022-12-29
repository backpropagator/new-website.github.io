#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n, m;
	cin>>m>>n;
	ll arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll ans = arr[m-1]-arr[0];
	for (int i = 0; i <= n-m; ++i)
	{
		ans = min(ans,arr[i+m-1]-arr[i]);
	}
	cout<<ans<<"\n";
}