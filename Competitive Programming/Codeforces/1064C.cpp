#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n;
	cin>>n;
	char s[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
	}
	sort(s,s+n);
	for (int i = 0; i < n; ++i)
	{
		cout<<s[i];
	}
	cout<<"\n";
}