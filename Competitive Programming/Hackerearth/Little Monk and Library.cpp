#include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	long long table[n], shelve[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>table[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>shelve[i];
	}
	sort(table,table+n);
	sort(shelve,shelve+n);
	long long tm = 0;
	for (int i = 0; i < n; ++i)
	{
		tm += abs(table[i] - shelve[i]);
	}
	cout<<tm<<"\n";
}