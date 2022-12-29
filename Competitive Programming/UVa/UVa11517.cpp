#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll tc, n, c, a;
	cin>>tc;
	while(tc--){
		cin>>n;
		cin>>c;
		ll cc[10001];
		//memset(cc,200,sizeof(cc));
		for (int i = 0; i < 10001; ++i)
		{
			cc[i] = 200;
		}
		//cout<<cc[200]<<"\n";
		cc[0] = 0;
		ll change[c];
		for (ll i = 0; i < c; ++i)
		{
			cin>>change[i]; 
			for(ll j= 10000-change[i]; j>=0; j--){
				if(cc[j] != 200){
					cc[j+change[i]] = min(cc[j+change[i]],cc[j]+1);
					//cout<<cc[j+change[i]]<<"\n";
				}
			}
		}
		while(cc[n] == 200)
			n++;

		printf("%lld %lld\n", n, cc[n]);
	}

}