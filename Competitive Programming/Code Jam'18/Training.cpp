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
//ll x, y;
/*char mat[55][55];
bool vis[55][55];
ll dr[] = {1,-1,0,0};
ll dc[] = {0,0,1,-1};
vector<pair<char,ll>> ans;*/




int main(){
	cout.precision(12);
	ll k=1;
	ll t;
	cin>>t;
	while(t--){
		ll n, r, c, sr, sc;
		/*sr--;
		sc--;*/
		string s;
		cin>>n>>r>>c>>sr>>sc;
		cin>>s;
		sr--;
		sc--;
		//bool vis[r+100][c+100];
		map<pair<ll,ll>,bool> vis;
		//memset(vis, false, sizeof vis);
		vis[make_pair(sr,sc)] = true;
		ll x = sr, y=sc;
		ll dx = 0;
		ll dy = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			char p = s[i];
			if(p == 'N'){
				x--;
				dx = -1;
				dy = 0;
			}
			else if(p == 'E'){
				y++;
				dx = 0;
				dy = 1;
			}
			else if(p == 'W'){
				y--;
				dx = 0;
				dy = -1;
			}
			else if(p == 'S'){
				x++;
				dx = 1;
				dy = 0;
			}
			if(vis[make_pair(x,y)]){
				//cout<<x<<" "<<y<<"\n";
				while(vis[make_pair(x,y)]){
					if(x+dx >= 0 && x+dx < r && y+dy >= 0 && y+dy <c){
						x+=dx;
						y+=dy;
					}else{
						break;
					}
					/*x += dx;
					y += dy;*/	
					//cout<<x<<" "<<y<<"\n";			
				}
				vis[make_pair(x,y)] = true;
			}else{
				vis[make_pair(x,y)] = true;
			}
			//cout<<x<<" "<<y<<"\n";
		}
		cout<<"Case #"<<k++<<": "<<x+1<<" "<<y+1<<"\n";
	}
	return 0;

}