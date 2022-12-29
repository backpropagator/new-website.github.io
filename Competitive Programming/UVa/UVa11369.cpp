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
		sort(a,a+n,greater<int>());
		int cost=0;
		int i=2;
		while(i < n){
			cost += a[i];
			i += 3;
		}
		cout<<cost<<'\n';
	}
}
