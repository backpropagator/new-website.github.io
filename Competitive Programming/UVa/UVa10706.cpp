#include <bits/stdc++.h>
using namespace std;
long long prev;

long long sum(int x){
	long long s = (x * (x+1)) / 2;
	return s;
}

long long BS(int l, int h, int a){
	while(h > l){
		int mid = (h + l) / 2;
		if(sum(mid) >= a && sum(mid-1) < a){
			return (a - sum(mid-1));
		}
		else if(sum(mid) < a && sum(mid+1) >= a){
			return (a - sum(mid));
		}
		else if(sum(mid) < a){
			l = mid;
		}
		else if(sum(mid) > a){
			h = mid;
		}
		return BS(l,h,a);
	}
	return -1;
}


int main(){
	ios_base::sync_with_stdio(false);
	int q, a;
	cin>>q;
	while(q--){
		cin>>a;
		cout<<BS(0,a,a)<<"\n";
	}
}