#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n;
	cin>>n;
	ll hlth[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>hlth[i];
	}
	ll res[n];
	//memset(res, 1, sizeof res);
	for (int i = 0; i < n; ++i)
	{
		res[i] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		if(hlth[i] > hlth[i-1] && res[i] <= res[i-1]){
			res[i] = res[i-1] + 1;
		}else{
			int j = i-1;
			while(hlth[j] > hlth[j+1] && res[j] <= res[j+1]){
				res[j] = res[j+1] + 1;
				j--;
			}
		}
		//cout<<res[i]<<"\n";
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += res[i];
	}
	cout<<ans<<"\n";
}