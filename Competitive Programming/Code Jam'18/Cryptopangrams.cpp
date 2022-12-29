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

pair<ll,ll> factor(ll n){
	pair<ll,ll> pr;
	for (ll i = 2; i <= sqrt(n); ++i)
	{
		if(n%i == 0){
			/*pr.first = i;
			pr.second = (n/i);*/
			pr = make_pair(i,n/i);
			break;
		}
	}
	return pr;
}

int main(){
	ll t, n, l;
	string s;
	cin>>t;
	for(int j=1; j<=t; j++){
		cin>>n>>l;
		vector<ll> v;
		vector<ll> q;
		vector<pair<ll,ll>> seq;
		ll x;
		map<ll,ll> freq;
		bool even;
		//set<ll> v;
		for (int i = 0; i < l; ++i)
		{
			cin>>x;
			q.pb(x);
			pair<ll,ll> tmp = factor(x);
			v.pb(tmp.first);
			v.pb(tmp.second);
			/*v.insert(tmp.first);
			v.insert(tmp.second);*/

			//seq.pb(tmp);
			/*if(freq[tmp.first] == 0){ 
				v.pb(tmp.first);
				freq[tmp.first]++;
			}
			if(freq[tmp.second] == 0){ 
				v.pb(tmp.second);
				freq[tmp.second]++;
			}*/
		}

		sort(v.begin(), v.end());
		vector<ll>::iterator ip; 
 
    	ip = unique(v.begin(), v.begin() + v.size()); 

	    v.resize(distance(v.begin(), ip));
		map<ll,char> id;
		/*set<ll>::iterator itr;
		ll iq=0;
		for(itr = v.begin(); itr != v.end(); itr++){
			id[*itr] = ('A'+iq);
			iq++;
		}
*/		//cout<<v.size()<<"\n";
		for (int i = 0; i < v.size(); ++i)
		{
			id[v[i]] = ('A'+i);
		}
		cout<<"Case #"<<j<<": ";

		ll a, b, last;
		//b = __gcd(q[0], q[1]);
		ll ptr = 0;
		while(__gcd(q[ptr], q[ptr+1]) == q[ptr] && __gcd(q[ptr], q[ptr+1]) == q[ptr+1]){
			ptr++;
		}
		b = __gcd(q[ptr], q[ptr+1]);
		cout<<id[q[0]/b]<<id[b];
		last = b;
		for (int i = 1; i < q.size(); ++i)
		{
			cout<<id[q[i]/last];
			last = (q[i]/last);
		}

		//cout<<"Case #"<<j<<": ";
		
		cout<<"\n";
	}

}