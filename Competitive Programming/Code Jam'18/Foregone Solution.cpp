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
	cin>>t;
	for(int j=1; j<=t; j++){
	    string s;
	    cin>>s;
	    string p = s, q = s;
	    for (int i = 0; i < s.length(); ++i)
	    {
	    	if(s[i] == '4'){
	    		p[i] = '3';
	    		q[i] = '1';
	    	}else{
	    		q[i] = '0';
	    	}
	    }
	    cout<<"Case #"<<j<<": "<<p<<" "<<q;
	    /*for (int i = dig.size()-1; i >= 0; i--)
	    {
	    	cout<<dig[i];
	    }
	    cout<<" ";
	    for (int i = idx.size()-1; i >= 0; i--)
	    {
	    	cout<<idx[i];
	    }*/
	    cout<<"\n";
	}

}