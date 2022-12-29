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
	cout.precision(12);
	ll n;
	cin>>n;
	ll w[n];
	map<ll,ll> idx;
	for (int i = 0; i < n; ++i)
	{
		cin>>w[i];
		idx[w[i]] = i;
	}
	sort(w,w+n);
	ll in=0, ex=0;
	ll st[2*n];
	string s;
	cin>>s;
	stack<ll> stk;
	for (int i = 0; i < 2*n; ++i)
	{
		if(s[i] == '0'){
			stk.push(idx[w[in]]);
			in++;
			st[i] = stk.top();
		}else{
			st[i] = stk.top();
			stk.pop();
		}
	}
	for (int i = 0; i < 2*n; ++i)
	{
		cout<<st[i]+1<<" ";
	}
	//cout<<"\n";

	/*ll cnt[2*n] = {0};
	for (int i = 0; i < 2*n; ++i)
	{
		if(s[i] == '0'){
			st[i] = idx[w[in]];
			cnt[st[i]]++;
			in++;
			if(in <= n && cnt[idx[w[in-1]]] < 2) ex = in-1;
		}else{
			st[i] = idx[w[ex]];
			cnt[st[i]]++;
			if(cnt[idx[w[ex-1]]] == 2){
				while(cnt[idx[w[ex]]] == 2) ex--;
				//ex++;
			}else{
				ex--;
			}
		}
		//cnt[st[i]]++;
		cout<<s[i]<<" "<<in<<" "<<ex<<"\n";
	}
	for (int i = 0; i < 2*n; ++i)
	{
		cout<<st[i]+1<<" ";
	}*/
	cout<<"\n";
	
}