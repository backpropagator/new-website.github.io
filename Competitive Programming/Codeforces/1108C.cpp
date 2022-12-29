#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
vector<string> s(7);

void init(){
	for (int i = 0; i < 7; ++i)
	{
		s[i] = "";
	}
	for (int i = 0; i < 200005; ++i)
	{
		if(i%3 == 0){
			s[1] += "R";
			s[2] += "G";
			s[3] += "B";
			s[4] += "R";
			s[5] += "G";
			s[6] += "B";
		}
		else if(i%3 == 1){
			s[1] += "G";
			s[2] += "B";
			s[3] += "R";
			s[4] += "B";
			s[5] += "R";
			s[6] += "G";
		}
		else if(i%3 == 2){
			s[1] += "B";
			s[2] += "R";
			s[3] += "G";
			s[4] += "G";
			s[5] += "B";
			s[6] += "R";
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
	ll n;
	cin>>n;
	string p;
	cin>>p;
	//string t1 = s[1].substr(0,n), t2 = s2.substr(0,n), t3 = s3.substr(0,n), t4 = s4.substr(0,n), t5 = s5.substr(0,n), t6 = s6.substr(0,n);

	ll cnt = INT_MAX;
	string ans;
	for (int i = 1; i < 7; ++i)
	{
		string t = s[i].substr(0,n);
		ll tmp=0;
		for (int i = 0; i < n; ++i)
		{
			if(t[i] != p[i]) tmp++;
		}
		//cnt = min(cnt,tmp);
		if(tmp <= cnt){
			cnt = tmp;
			ans = t;
		}
	}
	cout<<cnt<<"\n"<<ans<<"\n";

}

