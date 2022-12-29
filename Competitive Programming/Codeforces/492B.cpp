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
	cout.precision(12);
	ll t, n, l;
	//string s;
	cin>>n>>l;
	vector<ll> v(n);
	bool o1 = false, o2 = false;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		if(v[i] == 0) o1 = true;
		if(v[i] == l) o2 = true;
	}
	if(o1 && o2){
		sort(v.begin(), v.end());
		ll ans = 0;
		for (int i = 1; i < n; ++i)
		{
			ans = max(ans, v[i]-v[i-1]);
		}
		cout<<(double)ans/2.00<<"\n";
	}
	else if(!o1 && o2){
		sort(v.begin(), v.end());
		ll ans = 0;
		for (int i = 1; i < n; ++i)
		{
			ans = max(ans, v[i]-v[i-1]);
		}
		ans = max(ans,2*v[0]);
		cout<<(double)ans/2.00<<"\n";
	}
	else if(o1 && !o2){
		sort(v.begin(), v.end());
		ll ans = 0;
		for (int i = 1; i < n; ++i)
		{
			ans = max(ans, v[i]-v[i-1]);
		}
		ans = max(ans,2*(l-v[n-1]));
		cout<<(double)ans/2.00<<"\n";
	}
	else if(!o1 && !o2){
		sort(v.begin(), v.end());
		ll ans = 0;
		for (int i = 1; i < n; ++i)
		{
			ans = max(ans, v[i]-v[i-1]);
		}
		ans = max(ans,2*(l-v[n-1]));
		ans = max(ans,2*v[0]);
		cout<<(double)ans/2.00<<"\n";
	}

}