#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;
typedef pair<string,int> P;
typedef vector<int> vec;

int main(){
	ll n, L, v, l, r, ans;
	cin>>n;
	while(n--){
		cin>>L>>v>>l>>r;
		ans = (L/v);
		ll tmp = (r/v) - ((l-1)/v);
		cout<<ans-tmp<<"\n";
	}
}