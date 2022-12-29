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
#define vii			vector<vi>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define const N 1e5
using namespace std;
vii adj(26);
bool vis[26];
ll k;
char mn, th;
void dfs(ll u, ll c, ll prev){
	//cout<<char(u+'A')<<" ";
	if(c == k){
		vis[u] = true;
		char p = 'A'+u;
		//cout<<u;
		cout<<p<<" ";
		//dfs(u,0,u);
		c=-1;
	}
	//c=0;
	bool pos = true;
	for (int i = 0; i < adj[u].size(); ++i)
	{
		if(!vis[adj[u][i]] && adj[u][i] != prev){
			dfs(adj[u][i],c+1,u);
			pos = false;
			break;
		}
	}
	if(pos){
		cout<<"/"<<char(u+'A')<<"\n";
	}
	
}

int main(){
	string s;
	while(cin>>s && s!="#"){
		for (int i = 0; i < 26; ++i) adj[i].clear();
		for (int i = 0; i < 26; ++i) vis[i] = false;
		s.pop_back();
		istringstream iss(s);
		while(getline(iss,s,';'))
			for (int i = 2; i < s.size(); ++i)
				adj[s[0]-'A'].pb(s[i]-'A');
		/*for (int i = 0; i < adj.size(); ++i)
		{
			cout<<i<<": ";
			for (int j = 0; j < adj[i].size(); ++j)
			{
				cout<<adj[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		cin>>mn>>th>>k;
		vis[th-'A'] = true;
		dfs(mn-'A',1,th-'A');
	}

}