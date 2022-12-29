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
	cin>>n;
	map<char,ll> cls;
	string s;
	ll a[26] = {0}, b[26] = {0};
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		cls[s[0]]++;
	}
	map<char,ll>::iterator itr;
	for (itr = cls.begin(); itr != cls.end(); itr++)
	{
		ll tmp = itr->second;
		char c = itr->first;
		a[c-'a'] = tmp/2;
		b[c-'a'] = tmp - (tmp/2);
	}
	ll cnt=0;
	for (int i = 0; i < 26; ++i)
	{
		ll t1 = a[i], t2 = b[i];
		if(a[i]>0 || b[i]>0){
			cnt += (t1*(t1-1))/2;
			cnt += (t2*(t2-1))/2;
		}
	}
	cout<<cnt<<"\n";
}