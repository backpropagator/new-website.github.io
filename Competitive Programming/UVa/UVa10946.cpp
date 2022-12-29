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
ll x, y;
char mat[55][55];
bool vis[55][55];
ll dr[] = {1,-1,0,0};
ll dc[] = {0,0,1,-1};
vector<pair<char,ll>> ans;

bool isval(ll r, ll c){
	if(r>=0 && r<x && c>=0 && c<y) return true;
	else return false;
}

ll dfs(ll r, ll c, char col){
	//mat[r][c] = '.';
	vis[r][c] = true;
	//cout<<r<<" "<<c<<"\n";
	ll cn = 1;
	for (int i = 0; i < 4; ++i)
	{
		if(isval(r+dr[i],c+dc[i]) && mat[r+dr[i]][c+dc[i]] == col && !vis[r+dr[i]][c+dc[i]]){
			cn += dfs(r+dr[i],c+dc[i],col);
		}
	}
	return cn;
}

bool comp(pair<char,ll> p1, pair<char,ll> p2){
	if(p1.second != p2.second){
		if(p1.second > p2.second) return true;
		else return false;
	}else{
		return p1.first < p2.first ?  true :  false;
	}
}


int main(){
	cout.precision(12);
	ll k=1;
	while(cin>>x>>y && x+y){
		ans.clear();
		memset(vis, false, sizeof vis);

		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				cin>>mat[i][j];
			}
		}
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				if(mat[i][j] != '.' && !vis[i][j]){
					char c= mat[i][j];
					//cout<<dfs(i,j,c,1)<<"\n";
					ll tmp = dfs(i,j,c);
					//cout<<tmp<<"\n";
					ans.pb(make_pair(c,tmp));
				}
			}
		}
		sort(all(ans),comp);
		cout<<"Problem "<<k++<<":\n";
		for (int i = 0; i < ans.size(); ++i)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}

	}

}