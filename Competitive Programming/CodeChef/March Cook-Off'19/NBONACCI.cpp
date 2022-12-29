#include <bits/stdc++.h>


using namespace std;
typedef long long int ll;


int main()
{

	// freopen("in.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll n, q;
	cin>>n>>q;
	ll f[n+1];
	//ll ans = 
	for (int i = 0; i < n; ++i)
	{
		cin>>f[i];
	}
	ll ans = f[0];
	for (int i = 1; i < n; ++i)
	{
		ans = ans ^ f[i];
	}
	f[n] = ans;
	ll s[n+1];
	ll a1 = 0;
	for (int i = 0; i < n+1; ++i)
	{
		a1 = a1 ^ f[i];
		//cout<<f[i];
		s[i] = a1;
		//cout<<s[i];
	}
	ll k;
	for (int i = 0; i < q; ++i)
	{
		cin>>k;
		ll p = k%(n+1);
		if(p!=0){
			cout<<s[p-1]<<"\n";
		}else{
			cout<<s[n]<<"\n";
		}
	}

	return 0;
}