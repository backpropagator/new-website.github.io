#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int n, k;
string s;
vector<ll> v;

/*ll bt(ll i, ll cnt, ll sum){
	if(i == n){
		return sum;
	}
	if(cnt == k){
		if(s[i] != s[i+1]){
			return bt(i+1,0,v[i]+sum);
		}else{
			return bt(i+2,0,sum);
		}
	}
	if(cnt == k+1){
		return bt(i+2,0,sum);
	}
	else if(cnt > k){
		return -INT_MAX;
	}
	else if(s[i] != s[i+1]){
		return bt(i+1,0,v[i]+sum);
	}else{
		if(cnt == 0){
			return max(bt(i+1,cnt+2,v[i]+sum),bt(i+1,cnt,sum));
		}
		else{
			return max(bt(i+1,cnt+1,v[i]+sum),bt(i+1,cnt,sum));
		}
		if(cnt == 1 || cnt == 2){
			return bt(i+1, cnt+1, v[i]+sum);
		}else
			return max(bt(i+1,cnt+1,v[i]+sum),bt(i+1,0,sum));
}}
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	//ll n, k;
	cin>>n>>k;
	ll tmp, sum=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>tmp;
		v.pb(tmp);
		sum += v[i];
	}
	string s;
	cin>>s;
	ll som=0;
	//cout<<bt(0,0,0)<<"\n";
	for (int i = 0; i < n; ++i)
	{
		
			vector<ll> tmp;
			tmp.pb(v[i]);
			while(s[i] == s[i+1]) tmp.pb(v[i+1]), i++;
			sort(tmp.begin(), tmp.end());
			int l = tmp.size();
			for (int i = l-1; i >= max(0,l-k); i--)
			{
				som += tmp[i];
			}
		
	}
	cout<<som<<"\n";
}

