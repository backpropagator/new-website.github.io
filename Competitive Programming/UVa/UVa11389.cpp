#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, d, r;
	while(cin>>n>>d>>r && n+d+r){
		int m[n], e[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>m[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>e[i];
		}
		sort(m,m+n);
		sort(e,e+n,greater<int>());
		int money = 0;
		for (int i = 0; i < n; ++i)
		{
			int tmp = m[i] + e[i];
			if(tmp > d)
				money += (tmp-d);
		}
		cout<<money*r<<"\n";
	}
}