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
	ll n, x;
	cin>>n>>x;
	ll p[n];
	for (int i = 0; i < n; ++i)
	{
		//ll tmp;
		cin>>p[i];
		//p.pb(tmp);
	}
	ll cnt = 0, ptr = 0;
	while(x > 0){
		x -= p[ptr];
		ptr++;
		cnt++;
	}
	cout<<cnt<<"\n";
}