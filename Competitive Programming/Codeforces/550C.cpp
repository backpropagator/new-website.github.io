#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*bool dp(ll n){
	if(n%8 == 0){
		ans = n;
		return exists = true;
	}/*

	//string s = n + '0';
	//bool final
	for(ll i=0; i<act.length(); i++){
		string s = to_string(n);
		s.erase(i,1);
		s = s - '0';
		ll tmp = stoi(s,nullptr);
		if(dp(tmp)){
			exists = true;
			break;
		}
	}
	return exists;
}*/


int main(){
	string s;
	cin>>s;
	s = "00" + s;
	//string opt
	for (int i = 0; i < s.length(); ++i)
	{
		for(int j=i+1; j<s.length(); j++)
		{
			for(int k=j+1; k<s.length(); k++)
			{
				ll tmp = (s[i] - '0')*100 + (s[j] - '0')*10 + (s[k] - '0');
				if(tmp%8 == 0){
					cout<<"YES\n";
					cout<<tmp<<"\n";
					return 0;
				}
			}
		}
	}
	cout<<"NO\n";
}