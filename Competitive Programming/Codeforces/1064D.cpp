#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m, r, c, x, y, ans;
char maze[2005][2005];
bool vis[2005][2005];

ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

bool isvalid(ll cx, ll cy){
	if(cx >= 0 && cx < n && cy >= 0 && cy < m)
		return true;
	else
		return false;
}

void dfs(ll curx, ll cury, ll xleft, ll yleft){
	//if(curx )
	if(xleft < 0 || yleft < 0) return;

	vis[curx][cury] = true;
	ans++;
	//cout<<curx<<" "<<cury<<"\n";

	for (ll i = 0; i < 4; i++)
	{
		ll p = curx+dx[i];
		ll q = cury+dy[i];
		if(isvalid(p,q) && !vis[p][q] && p >= 0 && q >= 0){
			if(maze[p][q] != '*'){
				if(dy[i] == -1) dfs(p,q,xleft-1,yleft);
				else if(dy[i] == 1) dfs(p,q,xleft,yleft-1);
				else dfs(p,q,xleft,yleft);
			}
		}
	}
	
	
}

int main(){
	//int n, m, r, c, x, y;
	//ans = 0;
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);
	ans = 0ll;
	cin>>n>>m>>r>>c>>x>>y;
	memset(vis,false,sizeof vis);
	//char maze[n][m];
	//char c;
	//cout<<r<<" "<<c<<"\n";
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < m; ++j)
		{
			cin>>maze[i][j];
		}
	}
	dfs(r-1,c-1,x,y);
	cout<<ans<<"\n";
}