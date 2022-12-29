#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int n = s.length();
	int rem[n+1], tmp;
	for (int i = 1; i <= n; ++i)
	{
		tmp = s[i-1]-'0';
		rem[i] = tmp;
	}
	int ans=0, last=0;
	for (int i = 1; i <= n; ++i)
	{
		if(!rem[i]){
			ans++;
			last=0;
			continue;
		}
		if(!last){
			last = rem[i];
			continue;
		}
		if(last != rem[i]){
			ans++;
			last=0;
			continue;
		}
		if(i+2 > n)break; last=0; i++; ans++;
	}
	cout<<ans<<"\n";
}