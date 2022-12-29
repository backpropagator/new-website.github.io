#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin>>n>>s;
	int k = s.length();
	unsigned long long ans=1;
	for(int i=n; i>0; i-=k) ans *= i;
	cout<<ans<<"\n";
}