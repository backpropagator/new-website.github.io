#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int q){
	//sort
	int sum, tmp = 100000000, tmp1;
	for (int i = 0; i < n-1; ++i)
	{
		for(int j=i+1; j<n; j++)
		{
			tmp1 = abs(arr[j] + arr[i] - q);
			//tmp = arr[j] + arr[i-1] - q;
			if(tmp1 == 0)
				return (arr[j] + arr[i]);
			if(tmp1 < tmp){
				tmp = tmp1;
				sum = arr[j] + arr[i];
			}
		}
	}
	return sum;
}

int main(){
	int n, m, p=1, q;
	while(cin>>n){
		if(n == 0)
			break;

		int arr[n];
		//printf("Case %d:\n", p);
		for (int i = 0; i < n; i++)
		{
			cin>>arr[i];
		}
		cin>>m;
		sort(arr,arr+n);
		printf("Case %d:\n", p);
		while(m--){
			cin>>q;
			cout<<"Closest sum to "<<q<<" is "<<solve(arr,n,q)<<".\n";
		}
		p++;
	}
}