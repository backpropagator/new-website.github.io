#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n, cnt[100005] = {0};
	cin>>n;
	ll seq[n];
	ll a, b=0;
	memset(cnt,0,sizeof cnt);
	for (int i = 0; i < n; ++i)
	{
		cin>>seq[i];
		cnt[seq[i]]++;
		b = max(b,seq[i]);
	}
	ll m[b+1];
	m[0] = 0, m[1] = cnt[1];
	for(ll i=2; i<=b; i++){
		m[i] = max(m[i-1],m[i-2]+cnt[i]*i);
	}
	cout<<m[b]<<"\n";
}