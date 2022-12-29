#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n;
	cin>>n;
	ll v[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	ll cnt=v[n-1];
	ll prev = v[n-1];
	for(int i = n-2; i >= 0; i--)
	{
		if(prev == 0){
			continue;
		}
		if(v[i] < prev){
			cnt += (v[i]);
			prev = v[i];
		}

		else{
			cnt += (prev-1);
			prev--;
		}

	}
	cout<<cnt<<"\n";
}