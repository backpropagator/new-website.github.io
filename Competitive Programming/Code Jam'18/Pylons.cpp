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
ll r, c;
vector<pair<ll,ll>> mov;
map<pair<ll,ll>,bool> fil;

bool val(ll r1, ll r2, ll c1, ll c2){
	if(r1 == r2 || c1 == c2 || r1 + c1 == r2 + c2 || r1-c1 == r2-c2 || fil[make_pair(r2,c2)]) return false;
	else return true;
}

/*vector<pair<ll,ll>> mov;
map<pair<ll,ll>,bool> fil;*/
bool check(){
	bool pos = true;
	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			if(!fil[make_pair(i,j)]) pos = false;
		}
	}
	return pos;
}

bool backtrack(ll p, ll q){
	if(check()) return true;
	for (int i = 1; i < r+1; ++i)
	{
		for (int j = 1; j < c+1; ++j)
		{
			/*mov.pb(make_pair(i,j));
			fil[make_pair(i,j)] = true;*/
			if(val(p,i,q,j)){ 
				//cout<<i<<" "<<j<<"\n";
				mov.pb(make_pair(i,j));
				fil[make_pair(i,j)] = true;
				if(backtrack(i,j))
					return true;
				
				fil[make_pair(i,j)] = false;		
				mov.pop_back();
			}
			/*fil[make_pair(i,j)] = false;
			mov.pop_back();*/
		}
	}
	return false;
}


int main(){
	ll t;
	cin>>t;
	for (int j = 1; j <= t; ++j)
	{
		mov.clear();
		fil.clear();
		cin>>r>>c;
		bool pos = false;
		for (int i = 1; i < c+1; ++i)
		{
			mov.pb(make_pair(1,i));
			fil[make_pair(1,i)] = true;
			if(backtrack(1,i)){
				pos = true;
				break;
			}
				mov.clear();
				fil.clear();
			
			//mov.pop_back();
			//fil[make_pair(1,i)] = false;
		}
		cout<<"Case #"<<j<<": ";
		if(!pos){
			cout<<"IMPOSSIBLE\n";
		}else{
			cout<<"POSSIBLE\n";
			for (int i = 0; i < mov.size(); ++i)
			{
				cout<<mov[i].first<<" "<<mov[i].second<<"\n";
			}
		}
	}

}