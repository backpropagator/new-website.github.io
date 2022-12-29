#include <bits/stdc++.h>
using namespace std;

int main(){
	long long tc, n;
	cin>>tc;
	while(tc--){
		cin>>n;
		long long c[n], p[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>c[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>p[i];
		}
		long long cost = c[0]*p[0];
		long long minimum = 0;
		for (int i = 1; i < n; ++i)
		{
			if(c[minimum] > c[i]){
				minimum = i;
			}
			cost += c[minimum]*p[i];
		}
		cout<<cost<<"\n";
	}
}