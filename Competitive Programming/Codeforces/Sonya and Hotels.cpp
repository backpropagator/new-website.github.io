#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n, d;
	cin>>n>>d;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	ll cnt = 2;
	for (int i = 0; i < n-1; ++i)
	{
		if(a[i+1]-a[i] > (2*d)){
			cnt += 2;
		}
		else if(a[i+1]-a[i] == (2*d)){
			cnt++;
		}
	}
	cout<<cnt<<"\n";
}