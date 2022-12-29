#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	vector<ll> flowers(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>flowers[i];
	}
	sort(flowers.begin(), flowers.end(), greater<int>());
	ll cost = 0;
	for (int i = 0; i < n; ++i)
	{
		cost += (i/k + 1)*flowers[i]; 
	}
	cout<<cost<<"\n";
}