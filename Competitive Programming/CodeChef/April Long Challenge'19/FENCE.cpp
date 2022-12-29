#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int main(){
	ll t, n, m, k, r, c;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		map<pair<ll,ll>,int> pres;
		vector<pair<ll,ll>> idx;
		for (int i = 0; i < k; ++i)
		{
			cin>>r>>c;
			pres[make_pair(r,c)]++;
			idx.pb(make_pair(r,c));
		}
		ll cnt = (m+1)*(n+1);
		for (int i = 0; i < k; ++i)
		{
			pair<ll,ll> tmp = idx[i];
			if(tmp.F == 1 || tmp.F == n){
				cnt--;
			}
			if(tmp.S == 1 || tmp.S == m){
				cnt--;
			}
			if(tmp.F != 1 && pres[make_pair(tmp.F-1,tmp.S)] == 0){
				cnt--;
			}
			if(tmp.F != n && pres[make_pair(tmp.F+1,tmp.S)] == 0){
				cnt--;
			}
			if(tmp.S != 1 && pres[make_pair(tmp.F,tmp.S-1)] == 0){
				cnt--;
			}
			if(tmp.S != m && pres[make_pair(tmp.F,tmp.S+1)] == 0){
				cnt--;
			}
		}
		cout<<(m+1)*(n+1) - cnt<<"\n";
	}
}