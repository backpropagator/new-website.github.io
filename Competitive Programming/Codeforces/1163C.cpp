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
	vector<pair<ll,ll>> pts;
	ll x, y;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;
		pts.pb(make_pair(x,y));
	}
	ll t = (n*(n-1))>>1;
	map<pair<double,double>,ll> m;
	map<ll,ll> inf_m;
	ll cnt = 0;
	map<double,ll> slp;
	for (int i = 0; i < n; ++i)
	{
		double tmp, icpt;
		for (int j = i+1; j < n; ++j)
		{
			tmp = (double)(pts[j].second - pts[i].second)/(double)(pts[j].first - pts[i].first);
			icpt = (double)pts[j].second - ((double)pts[j].first*tmp);
			if(pts[j].first == pts[i].first){
				inf_m[pts[j].first]++;
			}else{
				m[make_pair(tmp,icpt)]++;
			}
			//slp[tmp]++;
			/*if(m[tmp] > 1){
				cnt += (m[tmp]);
			}*/
		}
	}
	map<pair<double,double>,ll>::iterator itr1;
	for (itr1 = m.begin(); itr1 != m.end(); itr1++)
	{
		slp[(itr1->first).first]++;
	}
	slp[INT_MAX] = inf_m.size();
	t = m.size() + inf_m.size();
	//cout<<t<<"\n";
	//cout<<m.size()<<" "<<inf_m.size()<<"\n";
	map<double,ll>::iterator itr;
	for (itr = slp.begin();itr != slp.end(); itr++)
	{
		if(itr->second > 1){
			ll tmp =  itr->second;
			cnt += (tmp*(tmp-1))/2;
		}
	}
	ll ans = t*(t-1)/2 - cnt;
	cout<<ans<<"\n";

}