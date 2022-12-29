#include <bits/stdc++.h>
#define pb(a) push_back(a)
typedef long long ll;
using namespace std;

int l, n;
int cuts[55];
int memo[55][55];

int dp(int left, int right){

	if(memo[left][right] != -1){
		return memo[left][right];
	}

	if((right-left) == 1){
		//memo[left][right] = 0;
		return 0;
	}

	int cost = INT_MAX;

	for (int i = left+1; i < right; i++)
	{
		cost = min(cost, dp(left,i)+dp(i,right)+(cuts[right]-cuts[left]));
	}
	return memo[left][right] = cost;
}

int main(){
	int a;
	while(cin>>l && l){
		memset(memo,-1,sizeof(memo));
		cin>>n;
		for (int i = 1; i <= n; ++i)
		{
			cin>>cuts[i];
		}
		cuts[0] = 0;
		cuts[n+1] = l;
		printf("The minimum cutting is %d.\n",dp(0,n+1));
		//cuts.clear();
	}
}