#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n){
	int cache[3];
	int count=0;
	for (int i = 1; i < n; ++i)
	{
		for(int j=0; j<i; j++)
		{
			if(a[j] <= a[i])
				count++;
		}
	}
	return count;
}

int main(){
	int tc;
	cin>>tc;
	int n;
	while(tc--){
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			//cout<<solve(arr,n)<<"\n";
		}
		cout<<solve(arr,n)<<"\n";
	}	
}
