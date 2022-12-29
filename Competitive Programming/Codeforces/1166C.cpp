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


typedef pair<ll,ll>iPair;

ll A[200001];

int main(){


ll n;

while(cin>>n){

        for(ll i=0;i<n;i++)cin>>A[i],A[i]=abs(A[i]);


        sort(A,A+n);

       // for(ll i=0;i<n;i++)cout<<A[i]<<" ";

       // nl


ll ans=0;

for(ll i=0;i<n;i++){

ll p=2*A[i];

  ll q=upper_bound(A+i+1,A+n,p)-(A+i+1);
ans+=q;



}

cout<<ans<<endl;



}

}