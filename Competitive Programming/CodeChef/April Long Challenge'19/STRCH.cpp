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
	ll t, n;
	string s;
	char c;
	cin>>t;
	while(t--){
		cin>>n>>s>>c;
		vector<ll> v;
		ll last = 0, sum=0;
		ll lb;
		for (int i = 0; i < n; ++i)
		{
			if(s[i] == c){
				v.pb(i+1-last);
				sum += (i+1-last);
				last = i+1;
				lb = i;
			}
		}
		v.pb(n-lb);
		sum += (n-lb);
		ll cnt=0;
		for (int i = 0; i < v.size(); ++i)
		{
			sum -= v[i];
			cnt += (sum*v[i]);
		}
		cout<<cnt<<"\n";
	}
}