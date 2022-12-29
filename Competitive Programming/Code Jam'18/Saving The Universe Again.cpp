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
int cases=1;
ll val(string s){
    ll ans=0;
    ll cur=1;
    for(auto i:s){
        if(i=='C')cur*=2;
        else ans+=cur;
    }
    return ans;
}
void solve(){
    cout<<"Case #"<<cases++<<": ";
    int D;
    cin>>D;
    string s;
    cin>>s;
    rep(_,0,1000){
        if(val(s)<=D){
            cout<<_<<endl;
            return;
        }
        for(int i=sz(s)-2;i>=0;i--){
            if(s.substr(i,2)=="CS"){
                swap(s[i],s[i+1]);
                break;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}