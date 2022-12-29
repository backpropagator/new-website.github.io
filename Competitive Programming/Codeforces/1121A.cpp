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
	ll n, m, k;
	cin>>n>>m>>k;
	ll p[n], s[n], c[k];
	map<ll,vector<ll>> sch;
	map<ll,ll> skl;
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
		sch[s[i]].pb(p[i]);
		skl[p[i]] = s[i];
	}
	for (int i = 0; i < k; ++i)
	{
		cin>>c[i];
	}
	map<ll, vector<ll>>::iterator itr;
	for(itr = sch.begin(); itr !=sch.end(); itr++){
		sort((itr->second).begin(),(itr->second).end(), greater<int>());
	}
	ll cnt=0;
	for (int i = 0; i < k; ++i)
	{
		if(sch[skl[p[c[i]-1]]][0] != p[c[i]-1]) cnt++;
	}
	cout<<cnt<<"\n";
}