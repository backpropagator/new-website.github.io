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
	ll p = v[0];
	vector <ll> q;
	for (int i = 1; i < p; ++i)
	{
		ll l = v[0]%i;
		bool pos = true;
		for (int j = 0; j < m; ++j)
		{
			if(v[j]%i != l) pos = false;
			if(!pos) break;
		}
		if(pos) q.pb(i);
	}
	for (int i = 0; i < q.size(); ++i)
	{
		cout<<q[i]<<" ";
	}
	cout<<"\n";
}