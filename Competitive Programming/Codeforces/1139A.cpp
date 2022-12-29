#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n;
	string s;
	cin>>n;
	cin>>s;
	ll cnt=0;
	for (int i = 0; i < n; ++i)
	{
		char c = s[i];
		if(c == '2' || c == '4' || c == '6' || c == '8' || c == '0'){
			cnt += (i+1);
		}
	}
	cout<<cnt<<"\n";
}