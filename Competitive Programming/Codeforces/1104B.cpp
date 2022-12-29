#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	string s;
	cin>>s;
	stack<char> stk;
	stk.push(s[0]);
	ll cnt = 0;
	for (int i = 1; i < s.length(); ++i)
	{
		if(stk.empty()){
			stk.push(s[i]);
		}
		else if(s[i] == stk.top()){
			stk.pop();
			cnt++;
		}else{
			stk.push(s[i]);
		}
	}
	//cnt /= 2;
	cnt = (s.length()-stk.size())/2;
	if(cnt%2 == 0) cout<<"No\n";
	else cout<<"Yes\n";
}

