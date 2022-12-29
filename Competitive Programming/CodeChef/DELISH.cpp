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
		ll v[n];
		ll neg=0;
		ll sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			if(v[i] < 0) neg++;
			sum += v[i];
		}
		sort(v,v+n);
		if(neg == n){
			cout<<abs(sum + 2*v[n-1])<<"\n";
		}
		else if(neg == 0){
			cout<<sum-(2*v[0])<<"\n";
		}
		else if(neg < n){
			ll s=0;
			for (int i = 0; i < neg; ++i)
			{
				s += v[i];
			}
			sum=0;
			for (int i = neg; i < n; ++i)
			{
				sum += v[i];
			}
			cout<<abs(s-sum)<<"\n";
		}
	}

}