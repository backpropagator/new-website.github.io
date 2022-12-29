#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	string s;
	cin>>s;
	string t;
	char rnk, st;
	rnk = s[0], st = s[1];
	bool sol = false;
	for (int i = 0; i < 5; ++i)
	{
		cin>>t;
		if(t[0] == rnk || t[1] == st){
			sol = true;
		}
	}
	if(sol) cout<<"YES\n";
	else cout<<"NO\n";
}