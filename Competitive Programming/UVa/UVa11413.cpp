#include <bits/stdc++.h>
using namespace std;
vector<int> bottle;
int n, m;

bool valid(int mid){
	int nc = 0, cap = 0;
	for(int i=0; i<n; i++){
		if(bottle[i] > mid)
			return false;
		if(cap + bottle[i] > mid)
			cap = 0;
		if(cap == 0)
			nc++;
		if(nc > m)
			return false;
		cap += bottle[i];
	}
	return true;
}

int main(){
	int a;
	while(scanf("%d %d",&n,&m) != EOF){
		int l=0, h=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a;
			h += a;
			bottle.push_back(a);
		}
		int best = h + 1;
		while(l <= h){
			int mid = (h + l)/2;
			if(valid(mid)){
				best = mid;
				h = mid-1;
			}else{
				l = mid + 1;
			}
		}
		cout<<best<<"\n";
		bottle.clear();
	}
}