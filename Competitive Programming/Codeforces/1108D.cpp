#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll n;
	string s;
	cin>>n>>s;
	ll cnt = 0;
	for (int i = 0; i < s.length()-1; ++i)
	{
		if(s[i] == s[i+1]){
			if(i == s.length()-2){
				if(s[i] == 'R') s[i+1] = 'B';
				else if(s[i] == 'B') s[i+1] = 'G';
				else s[i+1] = 'R';
			}
			else if(s[i] == s[i+2]){
				if(s[i] == 'R') s[i+1] = 'B';
				else if(s[i] == 'B') s[i+1] = 'G';
				else s[i+1] = 'R';
			}else{
				if((s[i] == 'R' || s[i+2] == 'R') && (s[i] == 'B' || s[i+2] == 'B')) s[i+1] = 'G';
				if((s[i] == 'R' || s[i+2] == 'R') && (s[i] == 'G' || s[i+2] == 'G')) s[i+1] = 'B';
				if((s[i] == 'G' || s[i+2] == 'G') && (s[i] == 'B' || s[i+2] == 'B')) s[i+1] = 'R';

			}
			cnt++;
		}
		//cnt++;
	}
	cout<<cnt<<"\n"<<s<<"\n";
}