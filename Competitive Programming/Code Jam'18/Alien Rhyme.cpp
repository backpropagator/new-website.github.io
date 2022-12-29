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
	//string s;
	cin>>t;
	for (int k = 1; k <= t; ++k)
	{
		cin>>n;
		vector<string> s(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>s[i];
		}
		map<string,set<ll>> cnt;
		//map<pair<char,ll>,ll> pos_cnt;
		for (int j = 0; j < n; ++j)
		{
			string tmp = s[j];
			for (int i = 0; i < tmp.length(); ++i)
			{
				string c = tmp.substr(i,tmp.length()-i);
				(cnt[c]).insert(j);
				//pos_cnt[make_pair(tmp[i],j)]++;
			}
		}
		map<string,set<ll>>:: iterator itr;
		ll mx = 0;
		for(itr = cnt.begin(); itr != cnt.end(); itr++){
			if((itr->second).size() >= mx){
				mx = (itr->second).size();
			}
		}
		cout<<"Case #"<<k<<": ";
		if(mx == 1) cout<<0<<"\n";
		else cout<<mx<<"\n";
	}

}