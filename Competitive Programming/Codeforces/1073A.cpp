#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;
	string a = "";
	for (int i = 0; i < n; ++i)
	{
		a += s[0];
	}
	if(s == a){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
		for (int i = 1; i < n; ++i)
		{
			if(s[i] != s[i-1]){
				cout<<s.substr(i-1,2)<<"\n";
				break;
			}
		}
	}
}