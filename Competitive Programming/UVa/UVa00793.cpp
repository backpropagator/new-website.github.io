#include <bits/stdc++.h>
using namespace std;
#define N 10001

int parent[N];
int rnk[N];

void make_set(int n){
	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
		rnk[i] = i;
	}
}

int find_set(int n){
	if(parent[n] == n)
		return n;
	if(parent[n] != n){
		return find_set(parent[n]);
	}
}

void unite(int x, int y){
	int px = find_set(x);
	int py = find_set(y);

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
	int cs;
	cin>>cs;
	int n, a, b, c1, c2;
	char w;
	string s;
	for(int i=1; i<=cs; i++){
		scanf("\n%d\n",&n);
		make_set(n);
		c1 = c2 = 0;
		while(1){
			//c1 = c2 = 0;
			if(!getline(cin,s) || s.empty())
				break;
			sscanf(s.c_str(),"%c %d %d",&w,&a,&b);
			if(w == 'c'){
				unite(a,b);
			}else{
				find_set(a) == find_set(b) ? c1++:c2++;
			}
		}
		if(i != 1)
			cout<<"\n";
		cout<<c1<<","<<c2<<"\n";

	}
}