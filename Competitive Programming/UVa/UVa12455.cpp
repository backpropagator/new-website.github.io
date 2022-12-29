#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int q, n;
	while(t--){
		cin>>n;
		cin>>q;
		int arr[q];
		int sum=0;
		for (int i = 0; i < q; ++i)
		{
			cin>>arr[i];
		}
		bool found = false;
		int i;
		for (i = 0; i < (1 << q); ++i)
		{
			sum = 0;
			for (int j = 0; j < q; ++j)
			{
				if(i & (1 << j))
					sum += arr[j];
			}
			if(sum == n){
				found = true;
				//cout<<"YES"<<"\n";
				break;
			}
		}
		if(found)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}