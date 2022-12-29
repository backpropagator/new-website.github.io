#include <bits/stdc++.h>
#define N 100000
using namespace std;

int parent[N];
int rnk[N];

void make_set(int n){
	for (int i = 0; i <= n; ++i)
	{
		parent[i] = i;
		rnk[i] = 1;
	}
}

int find_frnd(int x){
	if(parent[x] == x){
		return x;
	}
	return parent[x] = find_frnd(parent[x]);
}
//std::ios_base::sync_with_stdio(false);
void make_frnd(int x, int y){
	int px = find_frnd(x);
	int py = find_frnd(y);
	if(px == py){
		return;
	}
	if(rnk[px] > rnk[py]){
		rnk[px] += rnk[py];
		parent[py] = px;
	}else{
		rnk[py] += rnk[px];
		parent[px] = py;
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	make_set(n);
	int a, b;

	while(m--){
		cin>>a>>b;
		make_frnd(a,b);
	}

	for (int i = 1; i <= n; ++i)
	{
		cout<<rnk[parent[i]]-1;
		if(i != n){
			cout<<" ";
		}
	}
	cout<<"\n";
}

