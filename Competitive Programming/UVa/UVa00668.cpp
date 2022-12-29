#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, n;
	cin>>m;
	while(m--){
		cin>>n;
		int ans[1004], no = 0, sum = 0;
		for (int i = 2; sum + i <= n; ++i)
		{
			sum += i;
			ans[no] = i;
			no++;
		}
		int left = n - sum;
		for (int i = no-1; left > 0; i--, left--)
		{
			if(i < 0) i = no-1;
			ans[i]++;
		}
		cout<<ans[0];
		for (int i = 1; i < no; ++i)
		{
			cout<<" "<<ans[i];
		}
		cout<<"\n";
		if(m != 0)
			cout<<"\n";
	}
}