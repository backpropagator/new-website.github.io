#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

  	ll t;
  	string s;
  	cin>>t;
  	while(t--){
  		cin>>s;
  		ll a=0, b=0, c=0;
  		map<pair<ll,ll>,ll> mp;
  		mp[make_pair(0,0)] = 1;
  		ll res=0;
  		for (int i = 0; i < s.length(); ++i)
  		{
  			if(s[i] == 'a') a++;
  			else if(s[i] == 'b') b++;
  			else if(s[i] == 'c') c++;
  			pair<ll,ll> tmp;
  			tmp.first = a-b;
  			tmp.second = a-c;
  			res += mp[tmp];
  			mp[tmp]++;
  		}
  		cout<<res<<"\n";
  	}
}