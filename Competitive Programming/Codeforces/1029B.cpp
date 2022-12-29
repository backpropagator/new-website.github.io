#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
	ll n, a;
	cin>>n;
	vector<ll> arr;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		arr.pb(a);
	}
	ll ans = 0, j;
	for (int i = 0; i < n; ++i)
	{
		j=i;
		while(j+1 < n && arr[j+1] <= 2*arr[j])
			j++;

		ans = max(ans, j-i+1);
		i = j;
	}
	cout<<ans;

}