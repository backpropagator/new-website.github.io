#include <bits/stdc++.h>
using namespace std;
long long n, k;

/*bool CanSwallow(long long a, long long b){
	if(a < b && a+k >= b){
		return true;
	}
	else
		return false;
}*/

int main()
{
	long long a;
	cin>>n>>k;
	vector<long long> bac;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		bac.push_back(a);
	}
	sort(bac.begin(),bac.end());
	bac.push_back(int(2e9));
	int u = 0, ans = 0;
	for (int i = 0; i < n-1; ++i)
	{
		while(u < n && bac[i] == bac[u])
			u++;
		if(bac[u] - bac[i] > k){
			ans++;
		}
	}
	cout<<ans+1<<"\n";
	return 0;
}