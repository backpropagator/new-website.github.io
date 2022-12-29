#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll x, y, z, a, b, c;
	cin>>x>>y>>z>>a>>b>>c;

	a -= x;
	if(a < 0){
		cout<<"NO\n";
	}
	else if(a+b < y){
		cout<<"NO\n";
	}
	else{
		ll t = a+b-y+c;
		if(t < z){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
			//cout<<t<<"\n";
		}
	}


}

