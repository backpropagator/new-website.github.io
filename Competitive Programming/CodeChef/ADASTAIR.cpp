#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll t, n, k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ll h[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>h[i];
		}
		ll cnt = 0, cur = 0;
		for (int i = 0; i < n; ++i)
		{
			if((h[i]-cur) > k){
				if(((h[i]-cur)%k) != 0){
					cnt += (h[i]-cur)/k;
					cur = h[i];
				}else{
					cnt += ((h[i]-cur)/k) - 1;
					cur = h[i];
				}
			}else{
				cur = h[i];
			}
		}
		/*while(cur < h[n-1]){
			if(h[i]-cur > k){
				while(cur < h[i]){
					cur += k;
					cnt++;
				}
				if(cur > h[i]){
					cur = h[i];
					cnt--;
				}
			}else{
				cur = h[i];
			}
			i++;
		}*/
		cout<<cnt<<"\n";
	}
}