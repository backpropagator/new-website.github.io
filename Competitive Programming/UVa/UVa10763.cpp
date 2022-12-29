#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b;
	while(cin>>n && n){
		map<pair<int,int>,int> loc;
		for (int i = 0; i < n; ++i)
		{
			cin>>a>>b;
			pair<int,int> p = make_pair(a,b);
			loc[p]++;
		}
		map<pair<int,int>,int>::iterator itr;
		bool flag = true;
		for(itr = loc.begin(); itr != loc.end(); itr++)
		{
			pair<int,int> tmp1;
			tmp1 = itr->first;
			swap(tmp1.first,tmp1.second);
			if(loc[tmp1] != loc[itr->first]){
				flag = false;
				break;
			}
			//cnt++;
		}
		if(!flag){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
}