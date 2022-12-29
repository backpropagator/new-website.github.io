#include <bits/stdc++.h>
using namespace std;

int main(){
	//std::ios_base::sync_with_stdio(false);

	int tc, n;
	scanf("%d",&tc);
	long long q, t;
	long long cost[n][2];
	string name[n], ans;
	while(tc--){
		cin>>n;
		for (int i = 0; i < n; ++i){
			cin>>name[i]>>cost[i][0]>>cost[i][1];
		}
		cin>>q;
		while(q--){
			cin>>t;
			long long cnt = 0;
			for (int i = 0; i < n; ++i)
			{
				if(t >= cost[i][0] && t <= cost[i][1]){
					cnt++;
					ans = name[i];
				}
			}
			if(cnt == 1){
				cout<<ans<<"\n";
			}else{
				cout<<"UNDETERMINED\n";
			}
		}
		if(tc) cout<<"\n";
	}

}