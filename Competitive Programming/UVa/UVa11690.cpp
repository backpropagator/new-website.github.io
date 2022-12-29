#include <bits/stdc++.h>
#define N 1001
using namespace std;

int frnd[N];
int debt[N];

void make_set(int n){
	for (int i = 0; i < n; ++i)
	{
		frnd[i] = i;
	}
}

int find_frnd(int x){
	if(frnd[x] == x)
		return x;
	return frnd[x] = find_frnd(frnd[x]);
}

void make_frnd(int x, int y){
	int px = find_frnd(x);
	int py = find_frnd(y);

	if(px != py){
		debt[px] += debt[py];
		debt[py] = 0;
		frnd[py] = px;
	}
}

int main(){
	int tt;
	cin>>tt;
	int n, m;
	int a, b, c;
	while(tt--){
		cin>>n>>m;
		make_set(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>debt[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin>>a>>b;
			make_frnd(a,b);
		}
		int i;
		for (i = 0; i < n; ++i)
		{
			if(debt[i] != 0){
				cout<<"IMPOSSIBLE\n";
				break;
			}
		}
		if(i >= n-1){
			cout<<"POSSIBLE\n";
		}
	}
}