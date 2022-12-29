#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	ll a[26] = {0};
	ll cnt=0;

	for (int i = 0; i < n; ++i)
	{
		if(s[i] == s[i+1] && k != 1){
			cnt++;
			if(cnt+1 == k){
				a[s[i]-'a']++;
				i++;
				cnt=0;
			}
		}
		else if(k == 1){
			a[s[i]-'a']++;
		}
		else cnt=0;
	}	
	ll ans=0;
	for (int i = 0; i < 26; ++i)
	{
		ans = max(ans,a[i]);
	}
	cout<<ans<<"\n";
}

