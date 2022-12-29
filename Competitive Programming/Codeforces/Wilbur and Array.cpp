#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin>>n;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	ll cnt = 0, cur = 0;
	for (int i = 0; i < n; ++i)
	{
		cnt += abs(cur - a[i]);
		cur = a[i];
	}
	cout<<cnt<<"\n";
}
