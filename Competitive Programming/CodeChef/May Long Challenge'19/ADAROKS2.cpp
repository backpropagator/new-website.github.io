#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long int
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
map<pair<ll,ll>,bool> occupied;
char mat[105][105];

bool isvalid(ll a, ll b){
	if(occupied[make_pair(a,b)]){
		return false;
	}else{
		map<pair<ll,ll>, bool>::iterator itr1, itr2;
		for (itr1 = occupied.begin(); itr1 != occupied.end(); itr1++)
		{
			pair<ll,ll> t1 = itr1->first;
			for (itr2 = occupied.begin(); itr2 != occupied.end(); itr2++)
			{
				pair<ll,ll> t2 = itr2->first;
				if(itr1 != itr2){
					if(t1.first == a && t2.second == b && occupied[make_pair(t2.first,t1.second)]){
						return false;
					}
					if(t2.first == a && t1.second == b && occupied[make_pair(t1.first,t2.second)]){
						return false;
					}
				}
			}

		}
		return true;
	}
	return false;
}

bool backtrack(ll cnt){
	if(cnt == 8*n){
		//cout<<1<<" ";
		return true;
	}
	//cout<<1<<" ";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<i<<" "<<j<<endl;
			if(isvalid(i,j)){
				occupied[make_pair(i,j)] = true;
				mat[i][j] = 'O';
				if(backtrack(cnt+1)) return true;
				
				occupied[make_pair(i,j)] = false;
				mat[i][j] = '.';
				
			}
			if(i == n-1 && j == n-1) return false;
		}
	}
	return false;
}



int main(){
	ll t;
	cin>>t;
	while(t--){
		for (int i = 0; i < 105; ++i)
		{
			for (int j = 0; j < 105; ++j)
			{
				mat[i][j] = '.';
			}
		}
		cin>>n;
		//cout<<n<<"\n";
		bool b = backtrack(0);
		//cout<<n<<"\n";
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<mat[i][j];
			}
			cout<<"\n";
		}
	}

}