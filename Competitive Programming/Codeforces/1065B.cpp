#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin>>n>>m;
    if(n-(2*m) <= 0){
    	cout<<0<<" ";
    }else{
    	cout<<n-(2*m)<<" ";
    }
    ll mx = (n*(n-1))>>1;
    if(m == 0)
    		cout<<n<<"\n";
    else if(m >= mx)
    	cout<<"0\n";
    else{
    	
    	for (ll i = 0; i <= n; ++i)
    	{
    		ll tmp = (i*(i-1))>>1;
    		if(m <= tmp){
    			cout<<n-i<<"\n";
    			break;
    		}
    	}
    
    }
	
}