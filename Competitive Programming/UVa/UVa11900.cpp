#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	int tc, n, p, q, t=0;
	cin>>tc;

	while(tc--){
		cin>>n>>p>>q;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		int w=0, cnt=0, ptr=0;	
		for (int i = 0; i < n; ++i)
		{
			if((w + arr[i]) <= q && cnt < p){
				w += arr[i];
				cnt++;
			}
			else{
				break;
			}
		}
		printf("Case %d: %d\n",++t,cnt);
	}
}