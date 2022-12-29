#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;

vector<ll> memo;

void init(){
	memo.pb(0), memo.pb(1), memo.pb(2);
	ll i = 2;
	while(memo[memo.size()-1] < (ll)pow(2,31)){
		memo.pb(i*i);
		memo.pb(i*(i+1));
		i++;
	}
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    init();
	ll t, x, y, n;
	cin>>t;
	while(t--){
		cin>>x>>y;
		n = y-x;
		ll i=0, ans;
		while(1){
			if(memo[i] >= n){
				ans = i;
				break;
			}
			else i++;
		}
		cout<<ans<<"\n";
	}
}

