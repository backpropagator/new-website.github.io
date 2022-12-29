#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
vector<ll> v;
bool vis[55][55];
char mat[55][55];
ll r, c;
ll dr[] = {0,1,-1,0};
ll dc[] = {1,0,0,-1};
ll ptr;

bool isval(ll x, ll y){
	if(x >= 0 && x < r && y >= 0 && y < c) return true;
	else return false;
}

void dfs1(ll x, ll y){
	vis[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		if(isval(x+dr[i],y+dc[i]) && !vis[x+dr[i]][y+dc[i]] && mat[x+dr[i]][y+dc[i]] == 'X'){
			dfs1(x+dr[i],y+dc[i]);
		}
		/*if(isval(x+dr[i],y+dc[i]) && !vis[x+dr[i]][y+dc[i]] && mat[x+dr[i]][y+dc[i]] == '*'){
			dfs(x+dr[i],y+dc[i]);
		}*/
	}
	return;
}

void dfs(ll x, ll y){
	vis[x][y] = true;
	//ll ans = 0;
	for (int i = 0; i < 4; ++i)
	{
		if(isval(x+dr[i],y+dc[i]) && !vis[x+dr[i]][y+dc[i]] && mat[x+dr[i]][y+dc[i]] == 'X'){
			ptr++;
			dfs1(x+dr[i],y+dc[i]);
		}
		if(isval(x+dr[i],y+dc[i]) && !vis[x+dr[i]][y+dc[i]] && mat[x+dr[i]][y+dc[i]] == '*'){
			dfs(x+dr[i],y+dc[i]);
		}
	}
	//return ans;
}


int main(){
	cout.precision(12);
	ll k=1;
	while(cin>>c>>r && r+c){
		memset(vis, false, sizeof vis);
		v.clear();
		ptr=0;

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin>>mat[i][j];
			}
		}
		ll tmp;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if(!vis[i][j] && mat[i][j] == '*'){
					//v.pb(dfs(i,j));
					//cout<<i<<" "<<j;
					ptr=0;
					dfs(i,j);
					v.pb(ptr);
				}
			}
		}
		sort(all(v));
		cout<<"Throw "<<k++<<"\n";
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i];
			//v[i] == 0 ? cout<<"" : cout<<v[i];
			if(i != v.size()-1) cout<<" ";
		}
		cout<<"\n\n";
	}
}