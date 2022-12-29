#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

  	ll n, tmp;
  	cin>>n;
  	ll e=0, o=0;

  	map<ll,ll> mp;
  	mp[0] = 1;
  	ll res = 0;

  	for (int i = 0; i < n; ++i)
  	{
  		cin>>tmp;
  		if(tmp%2 == 0) e++;
  		else o++;
  		ll t = o-e;

  		res += mp[t];
  		mp[t]++;
  	}
  	cout<<res<<"\n";

}