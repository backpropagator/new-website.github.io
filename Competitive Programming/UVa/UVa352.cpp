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
ll n;
char mat[30][30];
bool vis[30][30];
ll dr[] = {1,0,1,-1,0,-1,1,-1};
ll dy[] = {0,1,1,0,-1,-1,-1,1};

bool isvalid(ll x, ll y){
	if(x >= 0 && x < n && y >= 0 && y < n){
		return true;
	}else{
		return false;
	}
}

void dfs(ll x, ll y){
	vis[x][y] = true;
	for (int i = 0; i < 8; ++i)
	{
		if(isvalid(x+dr[i],y+dy[i]) && !vis[x+dr[i]][y+dy[i]] && mat[x+dr[i]][y+dy[i]] == '1'){
			dfs(x+dr[i],y+dy[i]);
		}
	}
	return;
}

int main(){
	cout.precision(12);
	ll k = 1;
	while(cin>>n){
		memset(vis, false, sizeof vis);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>mat[i][j];
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(!vis[i][j] && mat[i][j] == '1'){
					ans++;
					dfs(i,j);
				}
			}
		}
		cout<<"Image number "<<k++<<" contains "<<ans<<" war eagles.\n";
	}


}