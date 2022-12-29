#include <bits/stdc++.h>
#define MAX 1000000
typedef long long ll;
using namespace std;

int main(){
	int t;
	ll n, t1, t2;
	cin>>t;
	while(t--){
		cin>>n;
		ll s[n], e[n]; 
		ll m = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>s[i]>>e[i];
			m = max(m,e[i]);
		}
		ll marks[m+2] = {0};
		for (int i = 0; i < n; ++i)
		{
			marks[s[i]]++;
			marks[e[i]]--;
		}
		ll ans = INT_MIN;
		ll cur = 0;
		for (int i = 0; i < m; ++i)
		{
			cur += marks[i];
			if(ans < cur){
				ans = cur;
			}
		}
		cout<<ans<<"\n";
	}
}