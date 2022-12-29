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
	ll t, n;
	cin>>n;
	string s;
	cin>>s;
	//string c = "", p = "";
	ll c=0;
	bool pos = true;
	vector<ll> v;
	ll p=0;
	for (int i = 0; i < n; ++i)
	{
		if(s[i] == '1') break;
		else p++;
	}
	for (int i = 0; i < n; ++i)
	{
		if(s[i] == '1'){
			v.pb(i);
			c=0;
		}else{
			c++;
		}
	}
	if(v.size() == 0 || c > 1 || p > 1){
		cout<<"No\n";
		return 0;
	}
	/*if(s[n-1] != '1'){
		v.pb(n-1);
	}*/
	for (int i = 0; i < v.size()-1; ++i)
	{
		if(v[i+1]-v[i] >3 || v[i+1]-v[i] == 1 ) pos = false;
	}
	//if(c > 2) pos = false;

	if(pos) cout<<"Yes\n";
	else cout<<"No\n";
	
}