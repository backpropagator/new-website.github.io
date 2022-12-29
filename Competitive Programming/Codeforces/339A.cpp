#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

int main(){
	string s;
	vector<int> seq;
	cin>>s;
	forn(i,s.length()){
		if(s[i] != '+'){
			seq.push_back(s[i] - '0');
		}
	}
	sort(seq.begin(), seq.end());
	forn(i,seq.size()){
		if(i != seq.size()-1){
			cout<<seq[i]<<"+";
		}else{
			cout<<seq[i]<<"\n";
		}
	}
}