#include <bits/stdc++.h>
#define N 10004
#define mod 1000000007
using namespace std;

int city[N];
int rnk[N];
int E[N];

void init(int n){
	for (int i = 0; i <= n; ++i)
	{
		city[i] = i;
		rnk[i] = 1;
	}
}

int find(int x){
	if(city[x] == x){
		return x;
	}
	return city[x] = find(city[x]);
}

void unite(int x, int y){
	int px = find(x);
	int py = find(y);
	if(px == py){
		return;
	}
	if(E[px] > E[py]){
		city[px] = py;
		//rnk[py] += rnk[px];
		rnk[px] = 1;
	}
	else if(E[px] < E[py]){
		city[py] = px;
		//rnk[px] += rnk[py];
		rnk[py] = 1;
	}
	else{
		city[py] = px;
		rnk[px] += rnk[py];
		rnk[py]=1;
	}
}

int main(){
	int n, k, a, b;
	cin>>n;
	init(n);
	for (int i = 1; i <= n; ++i)
	{
		cin>>E[i];
	}
	cin>>k;
	for (int i = 0; i < k; ++i)
	{
		cin>>a>>b;
		unite(a,b);
	}
	long long ans = 1;
	for (int i = 1; i <= n; ++i)
	{
		ans *= rnk[i];
	}
	cout<<ans%mod<<"\n";
}