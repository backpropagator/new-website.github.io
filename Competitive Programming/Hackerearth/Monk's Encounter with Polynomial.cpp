#include <bits/stdc++.h>
#define eps 1e-9
using namespace std;

int main(){
	int tc;
	cin>>tc;
	int a, b, c, k;
	while(tc--){
		cin>>a>>b>>c>>k;
		long long lo=0, hi=10000000;
		double mid, exp;
		while(lo < hi){
			mid = (hi + lo)/2;
			exp = (a * mid * mid) + (b * mid) + (c - k);
			if(exp >= 0)
				hi = mid;
			else
				lo = mid+1;
		}
		cout<<lo<<"\n";
	}
}