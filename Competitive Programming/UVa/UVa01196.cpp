#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct block
{
	int left, middle;
};

bool compare(block &a, block &b){
	return a.left == b.left ? a.middle < b.middle : a.left < b.left;
}

int main(){
	int n;
	while(cin>>n && n){
		block b[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>b[i].left>>b[i].middle;
		}
		if(n != 1){
			sort(b,b+n,compare);
			ll lis[n], m = 0;
			lis[0] = 1;
			for (int i = 1; i < n; ++i)
			{
				ll ans = 1;
				for(int j=0; j<i; j++)
				{
					if(b[j].middle <= b[i].middle){
						ans = max(ans,1+lis[j]);
					}
				}
							
				lis[i] = ans;
				m = max(m,lis[i]);
			}
			cout<<m<<"\n";
		}else{
			cout<<1<<"\n";
		}
	}
	cout<<"*\n";
}