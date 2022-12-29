#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll t, n;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		s = "+" + s;
		ll i=1;
		ll ans = 0;
		char prev = '+';
		/*while(i < s.length()){
			string t = "";
			while(s[i] != '+' || s[i] != '-' || s[i] != '*'){
				t += s[i];
				i++;
			}
			ll d = t - '0';
			if(prev == '+') ans += d;
			else if(prev == '-') ans -= d;
			else ans *= d; 
			prev = s[i+1];
			i++;
		}*/
		string d = "";
		for (int i = 0; i < s.length(); ++i)
		{
			if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '+'){
				if(prev == '+'){
					ans += stoi(d);
				}
				else if(prev == '-'){
					ans -= stoi(d);
				}
				else if(prev == '*'){
					ans *= stoi(d);
				}
				prev = s[i];
				d = "";
			}else{
				d += s[i];
			}

			if(s[i] == '='){
				d = "";
			}
		}
		if(ans == stoi(d)) cout<<"Valid Equation\n";
		else cout<<"Invalid Equation\n";
	}
}

