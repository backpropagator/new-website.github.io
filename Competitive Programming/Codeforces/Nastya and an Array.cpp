#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n;
	cin>>n;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	if(n == 1 && a[0] == 0){
		cout<<0<<"\n";
	}
	else if(n == 1 && a[0] != 0){
		cout<<1<<"\n";
	}
	else{
		sort(a,a+n);
		ll cnt;
		if(a[0] == 0)
			cnt = 0;
		else
			cnt = 1;
		for (int i = 1; i < n; ++i){
			if(a[i] != a[i-1] && a[i] != 0)
				cnt++;
		}
		cout<<cnt<<"\n";
	}
}