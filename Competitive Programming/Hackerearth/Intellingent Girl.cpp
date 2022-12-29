#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	string s;
	cin>>s;
	ll dp[s.length()] = {0};
	ll cnt = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		int curr = s[i] - '0';
		//cout<<curr<<"\n";
		if(curr%2 == 0)
			cnt++;
		//cout<<curr<<" "<<cnt<<"\n";
		dp[i] = cnt;
	}
	//ll back = 0;
	//cout<<dp[s.length()-1]-dp[0]<<" ";
	if(dp[0] == 0){
		cout<<dp[s.length()-1]-dp[0]<<" ";
	}else{
		cout<<dp[s.length()-1]<<" ";
	}
	for (int i = 1; i < s.length(); ++i)
	{
		//back += dp[i];
		cout<<dp[s.length()-1]-dp[i-1];
		if(i != s.length()-1)
			cout<<" ";
	}
	cout<<"\n";
}