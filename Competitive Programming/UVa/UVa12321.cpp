#include <bits/stdc++.h>
using namespace std;

int main(){
	int l, g;
	while(cin>>l>>g && l+g){
		int x, r;
		vector<pair<int,int>> interval;
		for (int i = 0; i < g; ++i)
		{
			pair<int,int> tmp;
			cin>>x>>r;
			tmp.first = x - r;
			tmp.second = x + r;
			interval.push_back(tmp);
		}
		int left=0, right=0, cnt=1;
		for (int i = 0; i < g; ++i)
		{
			if(right >= l)
				break;
			if(interval[i].first <= left){
				right = max(right,interval[i].second);
			}else{
				if(interval[i].first > right)
					break;
				left = right;
				cnt++;
				i--;
			}
		}
		if(right >= l)
			cout<<g-cnt<<"\n";
		else
			cout<<-1<<"\n";

	}
}