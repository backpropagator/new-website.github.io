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
char mat[5000][5000];
ll vis[5000][5000];
ll r, c, t, n;

pair<bool, pair<ll,ll>> dfs(ll x, ll y, ll cnt){
	if(x < 0 || x >= r){
		return make_pair(false, make_pair(cnt,0));
	}
	if(y < 0 || y >= c){
		return make_pair(false, make_pair(cnt,0));	
	}
	if(vis[x][y]){
		return make_pair(true, make_pair(vis[x][y]-1, cnt-vis[x][y]+1));
	}
	if(mat[x][y] == 'N'){
		vis[x][y] = cnt+1;
		return dfs(x-1, y, cnt+1);
	}
	else if(mat[x][y] == 'E'){
		vis[x][y] = cnt+1;
		return dfs(x, y+1, cnt+1);
	}
	else if(mat[x][y] == 'S'){
		vis[x][y] = cnt+1;
		return dfs(x+1, y, cnt+1);
	}
	else{
		vis[x][y] = cnt+1;
		return dfs(x, y-1, cnt+1);
	}
}

int main(){
	//cout.precision(12);
	//ll r, c, t, n;
	//string s;
	while(cin>>r>>c>>n && r+c+n){
		memset(vis, 0, sizeof vis);
		for (ll i = 0; i < r; ++i)
		{
			for (ll j = 0; j < c; ++j)
			{
				cin>>mat[i][j];
			}
		}
		pair<bool, pair<ll,ll>> ans = dfs(0,n-1,0);
		if(!ans.first){
			cout<<(ans.second).first<<" step(s) to exit\n";
		}else{
			cout<<(ans.second).first<<" step(s) before a loop of "<<(ans.second).second<<" step(s)\n";
		}
	}

}