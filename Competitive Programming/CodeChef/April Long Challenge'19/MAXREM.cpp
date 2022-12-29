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
	ll v[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	sort(v,v+n);
	ll a = v[n-1];
	ll b;
	bool pos = false;
	for (int i = n-1; i >= 0; i--)
	{
		if(v[i] != a){
			b = v[i];
			pos = true;
			break;
		}	
	}
	if(pos){
		cout<<b%a<<"\n";
	}else{
		cout<<"0\n";
	}
}