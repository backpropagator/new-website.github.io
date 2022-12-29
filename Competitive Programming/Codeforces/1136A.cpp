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
	ll v[105];
	ll n, l, r;
	cin>>n;
	map<pair<ll,ll>,ll> seg;
	for (int i = 1; i <= n; ++i)
	{
		cin>>l>>r;
		seg[make_pair(l,r)]=i;
	}
	ll k;
	cin>>k;
	map<pair<ll,ll>,ll>::iterator itr;
	for (itr = seg.begin(); itr != seg.end(); itr++)
	{
		if(k >= (itr->first).first && k <= (itr->first).second){
			cout<<n-(itr->second)+1<<"\n";
			break;
		}
	}
	//cout<<n-v[k]+1<<"\n";

}