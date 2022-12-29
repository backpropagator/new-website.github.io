#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int tc,n;
	cin>>tc;
	while(tc--){
		cin>>n;
		long long int x[n], y[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>x[i]>>y[i];
		}
		sort(x,x+n);
		sort(y,y+n);

		long long int area = max((x[n-1]-x[0]),(y[n-1]-y[0]));
		cout<<area*area<<"\n";
	}
}