#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    
	ll n, k;
	while(cin>>n>>k){
		ll ans=n, rem=n;
		while(rem >= k){
			ans += (rem/k);
			ll tmp = rem;
			rem = rem%k;
			rem += (tmp/k);
		}
		cout<<ans<<"\n";
	}
}

