#include <bits/stdc++.h>
using namespace std;
//int n, m;
vector<int> coin;
long long int dp[255];

long long int solve(int S[], int m, int n){
	if(n == 0)
		return 1;
	if(n < 0)
		return 0;
	if(m <= 0 && n >= 1)
		return 0;
	
	return solve(S,m-1,n) + solve(S,m,n-S[m-1]);
}

int main(){
	int n, m;
	cin>>n>>m;
	int arr[m];
	for (int i = 0; i < m; ++i)
	{
		cin>>arr[i];
	}
	long long int ans = solve(arr,m,n);
	cout<<ans<<"\n";
}