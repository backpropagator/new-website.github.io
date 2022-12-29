#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n+1];
	map<int,int> mp;
	for (int i = 1; i <= n; ++i)
	{
		cin>>arr[i];
		mp[arr[i]]++;
	}
	if(n == 1){
		cout<<1;
	}
	else{
	int res = n;
	for (int i = 1; i <= n; ++i)
	{
		mp[arr[i]]--;
		bool f = false;
		for (int j = 1; j <= 30; ++j)
		{
			if(mp[(1<<j) - arr[i]]){
				f = true;
				break;
			}
			
		}
		if(f)
			res--; mp[arr[i]]++;
	}
	cout<<res;
}
}
