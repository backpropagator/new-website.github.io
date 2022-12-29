#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		ll p = pow(2,n-1) - 1;
		ll q = pow(2,n-1);
		cout<<q-1<<"/"<<q<<"\n";
	}
}

