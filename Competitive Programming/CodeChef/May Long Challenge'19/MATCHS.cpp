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

ll find(ll x, ll y, ll no){
	if(x == 0 || y == 0){
		return no;
	}
	ll l = min(x,y), h = max(x, y);
	if(h%l == 0){
		return find(h%l, l, no+1);
	}
	else if(h == l + (h%l)){
		return find(h%l, l, no+1);
	}
	else if(l%(h%l) == 0){
		return find(l + (h%l), l, no+1);
	}else{
		return(h%l, l, no+1);
	}
}


int main(){
	ll t, n, m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ll p = find(n, m, 0ll);
		if(p%2 == 0) cout<<"Rich\n";
		else cout<<"Ari\n";
	}

}