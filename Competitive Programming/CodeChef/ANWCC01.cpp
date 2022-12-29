#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
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
		cout<<ceil(log(n)/log(2))<<"\n";
	}
}

