#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n;
	cin>>n;
	ll f = sqrt(n);
	if(f*f == n) cout<<(int)(2*f)<<"\n";
	else{
		ll s = (int)sqrt(n);
		ll sqr = s*s;
		//cout<<s<<" "<<sqr<<"\n";
		ll ans = 2*s + ((n-sqr)/(s+1)) + 1;
		cout<<ans<<"\n";
	}

}