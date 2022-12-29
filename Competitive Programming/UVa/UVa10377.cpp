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


int main(){
	ll t, r, c;
	cin>>t;
	string q;
	while(t--){
		getline(cin,q);
		cin>>r>>c;
		getline(cin,q);
		vector<string> mat;
		for (int i = 0; i < r; ++i)
		{
			string tmp;
			getline(cin,tmp);
			mat.pb(tmp);
		}
		//cout<<mat[0];
		/*for (int i = 0; i < r; ++i)
		{
			cout<<mat[i]<<"\n";
		}
*/		ll x, y;
		cin>>x>>y;
		string p;
		x--, y--;
		char prev = 'N';
		while(1){
			getline(cin,p);
			//if(p == "\n") break;
			bool done = false;
			//char prev = 'N';
			for (int i = 0; i < p.length(); ++i)
			{
				if(p[i] == ' ') continue;
				if(p[i] == 'R'){
					if(prev == 'N') prev = 'E';
					else if(prev == 'E') prev = 'S';
					else if(prev == 'S') prev = 'W';
					else if(prev == 'W') prev = 'N';
				}
				else if(p[i] == 'L'){
					if(prev == 'N') prev = 'W';
					else if(prev == 'E') prev = 'N';
					else if(prev == 'S') prev = 'E';
					else if(prev == 'W') prev = 'S';
				}
				else if(p[i] == 'F'){
					if(prev == 'N' && x-1 >= 0 && mat[x-1][y] != '*'){
						x--;
					}
					else if(prev == 'W' && y-1 >= 0 && mat[x][y-1] != '*'){
						y--;
					}
					else if(prev == 'E' && y+1 < c && mat[x][y+1] != '*'){
						y++;
					}
					else if(prev == 'S' && x+1 < r && mat[x+1][y] != '*'){
						x++;
					}
				}
				if(p[i] == 'Q'){
					done = true;
				}
			}
			if(done) break;
		}
		cout<<x+1<<" "<<y+1<<" "<<prev<<"\n\n";
	}
}