//#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 30002
int parent[N];
int rnk[N];

void make_set(int n){
	for(int i=0; i<n; i++){
		parent[i] = i;
		rnk[i] = 1;
	}
}

int find_set(int n){
	if(parent[n] == n){
		return n;
	}
	else{
		return find_set(parent[n]);
	}
}

void make_union(int x, int y){
	int px = parent[x];
	int py = parent[y];

	if(px == py){
		return;
	}
	if(rnk[px] > rnk[py]){
		rnk[px] += rnk[py];
		parent[y] = x;
	}
	else{
		rnk[py] += rnk[px];
		parent[x] = y;
	}
}

int main(){
	int tot, gr;
	int t, fm, m;
	while(cin>>tot>>gr ){
		if(tot == 0 && gr == 0)
			break;
		make_set(tot);
		while(gr--){
			cin>>t;
			for(int i=1; i<=t; i++){
				cin>>m;
				if(i == 1){
					fm = m;
				}else{
					make_union(fm,m);
				}
			}
		}
		int p = find_set(0);
		int count = 0;
		for (int i = 1; i < tot; ++i)
		{
			if(find_set(i) == p){
				count++;
			}
		}
		cout<<count+1<<"\n";
	}
}