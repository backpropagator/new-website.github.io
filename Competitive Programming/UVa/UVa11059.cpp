#include <bits/stdc++.h> 
using namespace std;


int main(){
	int n;
	long long ans = 0;
	int tc = 1;
	while(cin>>n){
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}

		for(int i=0; i<n; i++){
			int m = 1;
			for(int j=i; j<n; j++){
				m *= arr[j];
				if(m > ans)
					ans = m;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", tc, ans);
		tc++;
	}
}