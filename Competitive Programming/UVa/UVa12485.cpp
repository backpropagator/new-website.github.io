#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int n;
	while(cin>>n){
		ll sum=0;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			sum += arr[i];
		}
		if(sum%n){
			cout<<-1<<"\n";
		}else{
			int ans = 1;
			ll avg = sum/n;
			for (int i = 0; i < n; ++i)
			{
				if(arr[i] > avg){
					ans += (arr[i]-avg);
				}
			}
			cout<<ans<<"\n";
		}
	}
}