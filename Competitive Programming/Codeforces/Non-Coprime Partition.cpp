#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n;
	cin>>n;
	if(n <= 2){
		cout<<"No\n";
	}else{
		cout<<"Yes\n";
		ll k = (n%2 == 0) ? n/2 : (n+1)/2;
		cout<<1<<" "<<k<<"\n";
		cout<<n-1<<" ";
		for (int i = 1; i <= n; ++i)
		{
			if(i == k)
				continue;
			cout<<i<<" ";
		}
		cout<<"\n";
	}
}