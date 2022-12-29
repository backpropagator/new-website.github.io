#include <bits/stdc++.h>
#define N 5001
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

int find_set(int n){
	if(parent[n] == n)
		return n;
	return parent[n] = find_set(parent[n]);
}

void make_cycle(int x, int y){
	int px = find_set(x);
	int py = find_set(y);

	if(px == py)
		return;

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
	int c, r;
	string s, a, b;
	int max;
	while(cin>>c>>r){
		if(c==0 && r==0)
			break;

		map<string,int> cyc;
		make_set(c);
		for (int i = 1; i <= c; ++i)
		{
			cin>>s;
			cyc[s] = i;
		}
		for (int i = 0; i < r; ++i)
		{
			cin>>a>>b;
			make_cycle(cyc[a],cyc[b]);
		}
		max = 0;
		map<string,int>::iterator itr;
		for (itr = cyc.begin(); itr != cyc.end(); itr++)
		{
			if(rnk[itr->second] > max)
				max = rnk[itr->second];
		}
		cout<<max<<"\n";
	}
}