#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll n, m=0;
	cin>>n;
	ll v[n];
	map<ll,ll> frq;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		frq[v[i]]++;
		m = max(m,v[i]);
	}
	ll b=0;
	map<ll,ll>::iterator itr;
	for (itr = frq.begin(); itr != frq.end() ; ++itr)
	{
		if(m % (itr->first) == 0){
			frq[itr->first]--;
		}
		if(frq[itr->first] > 0){
			b = max(b,itr->first);
		}
	}
	cout<<m<<" "<<b<<"\n";
}

