#include <bits/stdc++.h>
using namespace std;

int maxSubArray(int arr[], int n){
	int s = arr[0];
	int cur = arr[0];
	for (int i = 1; i < n; ++i)
	{
		cur = max(arr[i], cur+arr[i]);
		s = max(s, cur);
	}
	return s;
}

int RSQ(int arr[], int n){
	int sum = 0, ans = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		if(ans < sum){
			ans = sum;
		}
		if(sum < 0)
			sum = 0;
	}
	return ans;
}

int main(){
	int tc, n;
	cin>>tc;
	while(tc--){
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		printf("%d %d\n", maxSubArray(arr,n), RSQ(arr,n));
	}
}
