#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long int
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
	ll t, n, z;
	cin>>t;
	while(t--){
		cin>>n>>z;
		ll a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		for (int i = 0; i < z; ++i)
		{
			for (int j = 0; j < n-1; ++j)
			{
				if(a[j] == 0 && a[j+1] == 1){
					a[j] = 1;
					a[j+1] = 0;
					j++;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}

}