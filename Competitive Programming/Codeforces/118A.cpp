#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

int main(){
	string o;
	cin>>o;
	string s;
	s = o;

	forn(i,o.length()){
		
			if(isupper(s[i])){
				s[i] = s[i] - 'A' + 'a';
			}

		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U' && s[i] != 'y' && s[i] != 'Y'){
			//o.erase(i,1);
			//continue;
			cout<<"."<<s[i];
		}
	}
	cout<<"\n";
}