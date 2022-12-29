#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	map<string,int> mp;
	string s;
	for (int i = 0; i <= n; ++i)
	{
		getline(cin,s);
		mp[s]++;
	}
	map<string,int>::iterator itr;
	int ans=0;
	string p;
	for(itr = mp.begin(); itr != mp.end(); itr++){
		if(itr->second > ans){
			ans = itr->second;
			p = itr->first;
		}
	}
	cout<<p<<"\n";
}