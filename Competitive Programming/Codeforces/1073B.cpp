#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	ll n;
	cin>>n;
	ll a, b;
	map<ll,ll> idx;
	for (ll i = 0; i < n; ++i)
	{
		cin>>a;
		idx[a] = i;
	}
	ll cur = 0;
	for (ll i = 0; i < n; ++i)
	{
		cin>>b;
		if(idx[b] < cur){
			cout<<0<<" ";
		}else{
			cout<<idx[b]-cur+1<<" ";
			cur = idx[b]+1;
		}
	}
	cout<<"\n";
}