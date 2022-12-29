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
	cin>>n;
	ll v[n];
	ll ma = 0, mi = INT_MAX, sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		ma = max(ma,v[i]), mi = min(mi,v[i]);
		sum += v[i];
	}
	ll t ;
	ll cost = INT_MAX;
	for (int i = 1; i <= ma; ++i)
	{
		ll tmp=0;
		for(int j=0; j<n; j++){
			if(v[j] < i){
				tmp += abs(v[j] - (i-1));
			}
			else if(v[j] > i){
				tmp += abs(v[j] - (i+1));
			}
		}
		if(tmp < cost){
			cost = tmp;
			t = i;
		}
	}
	cout<<t<<" "<<cost<<"\n";
}

