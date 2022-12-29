#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll tc, d, a, m, b, x;
	cin>>tc;
	while(tc--){
		cin>>d>>a>>m>>b>>x;
		if(d >= x){
			cout<<0<<"\n";
		}else{
			x -= d;
			ll cur, cursum;
			ll onetime = (m*a) + b, mnth = m+1;
			cursum = onetime * (x / onetime);
			cur = (mnth) * (x / onetime);
			ll cnt = 0;
			for (int i = 0; i < m; ++i)
			{
				cursum += a;
				cur++;
				if(cursum >= x){
					break;
				}
				//cur++;
			}
			if(cursum >= x){
				cout<<cur<<"\n";
			}else{
				cursum += b;
				cur++;
				cout<<cur<<"\n";
			}
		}

	}
}