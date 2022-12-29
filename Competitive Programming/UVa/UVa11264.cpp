#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc, n;
	cin>>tc;
	while(tc--){
		cin>>n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		int ans = 1, sum = a[0];
		for (int i = 1; i < n-1; ++i)
		{
			if(a[i+1] > a[i] + sum){
				ans++;
				sum += a[i];
			}
		}
		cout<<ans+1<<"\n";
	}
}