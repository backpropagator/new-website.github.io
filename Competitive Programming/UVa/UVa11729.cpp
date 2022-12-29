#include <bits/stdc++.h>
using namespace std;

struct soldier
{
	int u, w;
};

bool compare(soldier a, soldier b){
	return a.w > b.w;
}

int main(){
	int n, tc=1;
	while(cin>>n && n){
		soldier a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i].u>>a[i].w;
		}
		sort(a,a+n,compare);
		int last=0, sum=0;
		for (int i = 0; i < n; ++i)
		{
			last += a[i].u;
			sum = max(sum,last+a[i].w);
		}
		printf("Case %d: %d\n", tc, sum);
		tc++;
	}
}