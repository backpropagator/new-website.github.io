#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll a[18];

bool solvable(ll x, ll pos){
	if(pos == n){
		if(x%360 == 0) return true;
		else return false;
	}
	bool c1, c2;
	c1 = solvable(x + a[pos+1], pos+1);
	if(c1) return c1;
	c2 = solvable(x - a[pos+1], pos+1);
	if(c2) return c2;

	return false;
}


int main(){
	cin>>n;
	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sum += a[i];
	}
	if(sum%360 == 0) cout<<"YES\n";
	else if(solvable(a[0], 0)) cout<<"YES\n";
	else cout<<"NO\n";
}