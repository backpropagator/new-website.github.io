#include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	int n, m, a;
	cin>>n>>m;
	int k[n];
	map<int,int> f;

	for (int i = 0; i < n; ++i)
		cin>>k[i];
	for (int i = 0; i < m; ++i){
		cin>>a;
		f[a] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if(f.count(k[i]) == 1){
			cout<<k[i];
			cnt++;
			if(cnt != m)
				cout<<" ";
		}
		
	}
	//cout<<"\n";
}