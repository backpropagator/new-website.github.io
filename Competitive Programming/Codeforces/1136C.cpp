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
	ll n, m;
	cin>>n>>m;
	ll a[n][m], b[n][m];
	vector<vi> aa(n+m), bb(n+m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
			aa[i+j].pb(a[i][j]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>b[i][j];
			bb[i+j].pb(b[i][j]);
		}
	}
	bool pos = true;
	for (int i = 0; i < n+m; ++i)
	{
		sort(aa[i].begin(), aa[i].end());
		sort(bb[i].begin(), bb[i].end());
		if(aa[i] != bb[i]){
			pos = false;
			break;
		}
	}
	if(pos) cout<<"YES\n";
	else cout<<"NO\n";

}