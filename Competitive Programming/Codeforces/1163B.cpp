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
	ll n;
	cin>>n;
	ll u[n+1];
	map<ll,ll> freq;
	map<ll,ll> fof;
	bool ok = false;
	ll ans, mx = -1*INT_MAX;
	
	for (ll i = 1; i <= n; i++)
	{
		cin>>u[i];
		fof[freq[u[i]]]--;
		freq[u[i]]++;
		fof[freq[u[i]]]++;

		mx = max(mx, freq[u[i]]);

		if(fof[1] = i){
			ok = true;
		} 
		else if(fof[i] == 1){
			ok = true;
		}
		else if(fof[1] == 1 && fof[mx]*mx == i-1){
			ok = true;
		}
		else if(fof[mx] == 1 && fof[mx-1]*(mx-1) == i-mx){
			ok = true;
		}
		if(ok) ans = i;
	}
	cout<<ans<<"\n";
}