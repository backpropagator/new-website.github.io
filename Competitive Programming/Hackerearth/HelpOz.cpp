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
	ll m;
	cin>>m;
	ll v[m];
	for (int i = 0; i < m; ++i)
	{
		cin>>v[i];
	}
	sort(v,v+m);
	ll p = v[m-1]-v[0];
	vector<ll> f;
	for (int i = 1; i <= sqrt(p); ++i)
	{
		if(p%i == 0){
			if(i != sqrt(p)){
				f.pb(i);
				f.pb(p/i);
			}else{
				f.pb(i);
			}
		}
	}
	vector<ll> a;
	for (int i = 0; i < f.size(); ++i)
	{
		ll c = f[i];
		ll l = v[0]%c;
		bool pos = true;
		for (int j = 0; j < m; ++j)
		{
			if(v[j]%c != l){
				pos = false;
				break;
			}
			//if(pos) a.pb(c);
		}
		if(pos) a.pb(c);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); ++i)
	{
		if(a[i] != 1) cout<<a[i]<<" ";
	}
	cout<<"\n";
}