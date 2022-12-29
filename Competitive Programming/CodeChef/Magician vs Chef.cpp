#include <bits/stdc++.h>
#define MAX 1000000001
typedef long long ll;
using namespace std;

int main(){
	ll t, n, s, x, a, b;
	cin>>t;
	while(t--){
		cin>>n>>x>>s;
		bool box[n];
		memset(box, false, sizeof box);
		box[x-1] = true;
		for (int i = 0; i < s; ++i)
		{
			cin>>a>>b;
			if(box[a-1] == true){
				box[b-1] = true;
				box[a-1] = false;
			}else if(box[b-1]){
				box[a-1] = true;
				box[b-1] = false;
			}
		}
		ll ans;
		for (int i = 0; i < n; ++i)
		{
			if(box[i]){
				ans = i+1;
				break;
			}
		}
		cout<<ans<<"\n";
	}
}