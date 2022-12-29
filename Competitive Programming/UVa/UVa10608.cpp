#include <bits/stdc++.h>
#define N 30001
using namespace std;
int parent[N];
int rnk[N];

void make_sets(int n){
	for (int i = 0; i <= n; ++i)
	{
		parent[i] = i;
		rnk[i] = 1;
	}
}

int find_set(int n){
	if(parent[n] == n)
		return n;

	return parent[n] = find_set(parent[n]);
}

void make_frnd(int x, int y){
	int px = find_set(x);
	int py = find_set(y);

	if(px == py){
		return;
	}
	if(rnk[px] > rnk[py]){
		rnk[px] += rnk[py];
		parent[py] = px;
	}
	else{
		rnk[py] += rnk[px];
		parent[px] = py;
	}
}

int main(){
	int tt;
	cin>>tt;
	int n, m;
	int a, b;
	int max;
	while(tt--){
		cin>>n>>m;
		make_sets(n);
		while(m--){
			cin>>a>>b;
			make_frnd(a,b);
		}
		max = 0;
		for (int i = 1; i <= n; ++i)
		{
			if((rnk[i]) > max)
				max = rnk[i];
		}
		cout<<max<<"\n";
	}
}
