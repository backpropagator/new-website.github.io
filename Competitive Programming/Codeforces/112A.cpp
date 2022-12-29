#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

int main(){
	string s, t;
	cin>>s;
	cin>>t;
	int o = 0;
	forn(i,s.length()){
		if(isupper(s[i]))
			s[i] = s[i] - 'A' + 'a';
		if(isupper(t[i]))
			t[i] = t[i] - 'A' + 'a';

		if(s[i] < t[i]){
			o = -1;
			break;
		}
		else if(s[i] > t[i]){
			o = 1;
			break;
		}
	}
	cout<<o<<"\n";
}