#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		ll totbit = log2(n)+1;	
		ll setbit = __builtin_popcount (n);
		ll ans = (int)pow(2,setbit);
		//cout<<totbit<<"\n";
		//cout<< __builtin_popcount (n)<<"\n";
		cout<<ans<<"\n";
	}
}