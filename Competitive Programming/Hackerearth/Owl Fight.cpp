#include <bits/stdc++.h>
#define N 100001
using namespace std;
int frnd[N];
int rnk[N];

void make_set(int n){
	for (int i = 0; i <= n; ++i)
	{
		frnd[i] = i;
		rnk[i] = i;
	}
}

int find_frnd(int x){
	if(frnd[x] == x){
		return x;
	}
	return find_frnd(frnd[x]);
}

void make_frnd(int x, int y){
	int px = find_frnd(x);
	int py = find_frnd(y);

	if(px == py){
		return;
	}
	if(px > py){
		//rnk[px] += rnk[py];
		frnd[py] = px;
	}else{
		//rnk[py] += rnk[px];
		frnd[px] = py;
	}
}

void solve(int a, int b){
	int pa = find_frnd(a);
	int pb = find_frnd(b);
	if(pa != pb){
		if(rnk[pa] > rnk[pb]){
			cout<<a<<"\n";
		}
		else if(rnk[pb] > rnk[pa]){
			cout<<b<<"\n";
		}
		else if(rnk[pa] == rnk[pb]){
			a > b ? cout<<a<<"\n" : cout<<b<<"\n";
		}
	}else{
		cout<<"TIE\n";
	}
}

int main(){
	int n, m, q, a, b;
	cin>>n>>m;
	//int owl[n+1];
	make_set(n);
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;
		make_frnd(a,b);
	}
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		cin>>a>>b;
		solve(a,b);
		/*if(rnk[find_frnd(a)] > rnk[find_frnd(b)]){

		}*/
	}
}