#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int count = 0;
	int l=0, r=n-1;
	while(a[l]<=k || a[r]<=k){
		if(l == r){
			if(a[l] <= k){
				count++;
				break;
			}else{
				break;
			}
		}

		if(a[l]<=k){
			count++;
			l++;
		}
		else if(a[r]<=k){
			count++;
			r--;
		}
		/*if(l == r)
			break;*/
	}
	cout<<count<<"\n";
}