#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
map<string, int> memo;

ll dp(string s){
	if(memo[s]) return memo[s];

	int i=0, r=0;
	while(i < s.size()){
		int j = i+1;
		while(s[i] == s[j] && j < s.size()) j++;
		if(j-i > 1){
			r = dp(s.substr(0,i)+s.substr(j));
			if(r) break;
		}
		i = j;
	}
	return memo[s]=r;
}



int main(){
	memo[""] = 1;
	ll t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		cout<<dp(s)<<"\n";
	}
}