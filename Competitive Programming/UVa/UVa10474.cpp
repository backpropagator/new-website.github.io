#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, q, tc = 1, a;
	while(cin>>n>>q){
		if(n == 0 && q == 0)
			break;
		vector<int> arr;
		for (int i = 0; i < n; ++i)
		{
			cin>>a;
			arr.push_back(a);
		}
		printf("CASE# %d:\n", tc);
		sort(arr.begin(), arr.end());
		while(q--){
			cin>>a;
			vector<int>::iterator itr = lower_bound(arr.begin(),arr.end(),a);
			int ans = *(itr);
			if(ans != a){
				cout<<a<<" not found"<<"\n";
			}else{
				int x = itr - arr.begin() + 1;
				//int ans = *(itr);
				printf("%d found at %d\n", ans, x);
			}
		}
		tc++;
	}
}