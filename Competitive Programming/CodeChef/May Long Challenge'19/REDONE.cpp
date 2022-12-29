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
ll fact[1000005];

void factorial(){
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i < 1000005; ++i)
	{
		fact[i] = (fact[i-1]%hell)*(i%hell);
		if(fact[i] == 0){
			cout<<i;
			break;
		}
		//cout<<fact[i]<<" ";
	}
}

int main(){
	factorial();
	ll t, n;
	cin>>t;
	while(t--){

		cin>>n;
		ll a = (n-1)%hell;
		ll b = (fact[n]%hell + fact[n-1]%hell - 1%hell)%hell;
		ll ans = (a%hell + b%hell + (a%hell * b%hell))%hell;
		cout<<ans%hell<<"\n";
	}

}