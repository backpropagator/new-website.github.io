#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int arr[n], pivot;

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		if(arr[i] == m){
			pivot = i;
		}
	}
	ll sum=0;
	map<ll,ll> mp;
	mp[0] = 1;
	for (int i = 0; i < pivot; ++i)
	{
		if(arr[i] < m){
			sum--;
		}
		else if(arr[i] > m){
			sum++;
		}
		mp[sum]++;
	}
	ll ans = 0;
	for (int i = pivot; i < n; ++i)
	{
		if(arr[i] < m){
			sum--;
		}
		else if(arr[i] > m){
			sum++;
		}
		ans += mp[sum]+mp[sum-1];
	}
	cout<<ans<<"\n";


}