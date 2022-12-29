#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n, m;
	cin>>n>>m;
	ll arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	ll rem = 0, cnt = 0, sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cnt = 0;
		sum += arr[i];
		if(sum >= m){
			cnt += (sum/m);
			sum = sum%m;
			//cnt += (sum/m);
		}
		cout<<cnt;
		if(i != n-1)
			cout<<" ";
	}
	cout<<"\n";
}