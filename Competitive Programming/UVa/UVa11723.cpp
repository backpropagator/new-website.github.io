#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    
    ll r, n;
    ll t=1;
    while(cin>>r>>n && (r+n)){
    	ll ans = (r/n);
    	if(ans*n == r && ans <= 26){
    		cout<<"Case "<<t<<": "<<ans-1<<"\n";
    	}
    	else if(ans <= 26){
    		cout<<"Case "<<t<<": "<<ans<<"\n";
    	}else{
    		cout<<"Case "<<t<<": "<<"impossible"<<"\n";
    	}
    	t++;
    }
}
