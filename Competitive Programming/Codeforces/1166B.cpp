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
	ll t, n;
	//string s;
	cin>>n;
	bool pos = false;
	ll x, y;
	for (int i = 1; i <= sqrt(n); ++i)
	{
		if(n%i == 0){
			if(i >= 5 && (n/i) >= 5){
				x = i;
				y = n/i;
				pos = true;
				break;
			}
		}
	}
	if(!pos){
		cout<<-1<<"\n";
	}else{
		string ans[5];// = ["aeiou","eioua","iouae","ouaei","uaeio"];
		ans[0] = "aeiou", ans[1] = "eioua", ans[2] = "iouae", ans[3] = "ouaei", ans[4] = "uaeio";
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				cout<<ans[i%5][j%5];
			}
			//cout<<"\n";
		}
		cout<<"\n";
	}
}