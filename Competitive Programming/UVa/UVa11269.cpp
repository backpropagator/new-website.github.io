#include <bits/stdc++.h>
using namespace std;

struct work
{
	int s, g;
};

bool compare1(work a, work b){
	return a.s <= b.s;
}

bool compare2(work a, work b){
	return a.g > b.g;
}

int main(){
	int n;

	while(cin>>n){
		work a[n], f[n], l[n];

		for (int i = 0; i < n; ++i)
		{
			cin>>a[i].s;
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i].g;
		}
		int n1 = 0;
		int n2 = 0;
		for (int i = 0; i < n; ++i)
		{
			if(a[i].s <= a[i].g){
				f[n1] = a[i];
				n1++;
			}else{
				l[n2] = a[i];
				n2++;
			}
		}

		sort(f,f+n1,compare1);
		sort(l,l+n2,compare2);

		for (int i = 0; i < n1; ++i)
		{
			a[i] = f[i];
		}
		for (int i = 0, j = n1; i < n2; ++i, ++j)
		{
			a[j] = l[i];
		}
		int ans = a[0].s,tmp = a[0].s;
		for (int i = 1; i < n; ++i)
		{
			tmp += a[i].s;
			ans = max(ans+a[i-1].g,tmp);
		}
		ans += a[n-1].g;
		cout<<ans<<"\n";
	}
}