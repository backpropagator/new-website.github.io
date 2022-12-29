#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll t, n;
	cin>>t;
	for (int tc = 1; tc <= t; ++tc)
	{
		cin>>n;
		ll in[n], d[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>in[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>d[i];
		}

		ll lis[n], lds[n], increasing=0, decreasing=0;
		//lis[0] = d[0], lds[0] = d[0];

		for(int i=0; i<n; i++){
			ll tmp1 = d[i], tmp2 = d[i];
			lis[i] = lds[i] = d[i];
			for(int j=0; j<i; j++){
				if(in[j] < in[i]){
					lis[i] = max(lis[i],tmp1+lis[j]);
				}
				if(in[j] > in[i]){
					lds[i] = max(lds[i],tmp2+lds[j]);
				}
			}
			/*lis[i] = tmp1;
			lds[i] = tmp2;*/
			increasing = max(increasing,lis[i]);
			decreasing = max(decreasing,lds[i]);
		}
		printf("Case %d. ", tc);
		if(increasing >= decreasing){
			printf("Increasing (%lld). Decreasing (%lld).\n", increasing, decreasing);
		}else{
			printf("Decreasing (%lld). Increasing (%lld).\n", decreasing, increasing);
		}
	}
}