#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
	ll n, L, a, l, t;
	cin>>n>>L>>a;
	vector<ll> len, time;
	if(n == 0){
		cout<<L/a<<"\n";
		//continue;
	}else{
	for (int i = 0; i < n; ++i)
	{
		cin>>t>>l;
		time.push_back(t), len.push_back(l);
	}
	ll cnt = 0;
	for (int i = 0; i < n-1; ++i)
	{
		cnt += (time[i+1] - time[i] - len[i])/a;
	}
	cnt += (L - time[n-1] - len[n-1])/a;
	cnt += (time[0])/a;
	cout<<cnt<<"\n";
	}
}