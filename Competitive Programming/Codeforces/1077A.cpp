#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n, a, b, k, t;
	cin>>t;
	while(t--){
		cin>>a>>b>>k;
		cout<<(a*(k-(k/2))-(b*(k/2)))<<"\n";
	}
}