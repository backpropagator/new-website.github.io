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
char mat[205][205];
bool vis[205][205];
ll n;

void dfs(ll x, ll y, char col){
	vis[x][y] = true;
	if(x-1 >= 0 && !vis[x-1][y] && mat[x-1][y] == col){
		dfs(x-1,y,col);
	}
	if(x+1 < n && !vis[x+1][y] && mat[x+1][y] == col){
		dfs(x+1,y,col);
	}
	if(y+1 < n && !vis[x][y+1] && mat[x][y+1] == col){
		dfs(x,y+1,col);
	}
	if(y-1 >= 0 && !vis[x][y-1] && mat[x][y-1] == col){
		dfs(x,y-1,col);
	}
	if(y+1 < n && x+1 < n && !vis[x+1][y+1] && mat[x+1][y+1] == col){
		dfs(x+1,y+1,col);
	}
	if(y-1 >= 0 && x-1 >= 0 && !vis[x-1][y-1] && mat[x-1][y-1] == col){
		dfs(x-1,y-1,col);
	}
	return;
}

int main(){
	//ll n;
	ll k = 1;
	while(cin>>n && n){
		memset(mat, '0', sizeof mat);
		memset(vis, false, sizeof vis);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>mat[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if(!vis[0][i] && mat[0][i] == 'b'){
				dfs(0,i,'b');
			}
		}
		cout<<k<<" ";
		bool pos = false;
		for (int i = 0; i < n; ++i)
		{
			if(vis[n-1][i] && mat[n-1][i] == 'b'){
				pos = true;
				break;
			}
		}
		if(pos){
			cout<<"B\n";
			continue;
		}
		//memset(vis, false, sizeof vis);
		for (int i = 0; i < n; ++i)
		{
			if(!vis[i][0] && mat[i][0] == 'w'){
				dfs(i,0,'w');
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if(vis[i][n-1] && mat[i][n-1] == 'w'){
				pos = true;
				break;
			}
		}
		if(pos){
			cout<<"W\n";
			
		}
		k++;
	}

}