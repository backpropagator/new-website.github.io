#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
vector<int> v,v1;
map<int,int> mp;
int main()
{
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while(t--)
	{
		v.clear(); mp.clear(); v1.clear();
		vector<int> ans;
		double diff=1000000000;
		int n; cin >> n;
		for(int i=0;i<n;i++)
		{
			int val;cin >> val;
			if(mp[val] == 0) v.push_back(val);
			mp[val]++;
			if(mp[val] >= 4)
			{
				diff = 16.0;
				ans.clear();
				for(int j=0;j<4;j++) ans.push_back(val);
			}
		}
		for(int i=0;i<v.size();i++) if(mp[v[i]] > 1) v1.push_back(v[i]);
		sort(v1.begin(),v1.end());
		for(int i=1;i<v1.size();i++)
		{
			double len=(double)(v1[i]+0.0), wid = (double)(v1[i-1]+0.0);
			double val = ((2.0*(len+wid))*(2.0*(len+wid)))/(len*wid);
			if(val > diff) continue;
			diff = val;
			ans.clear();
			for(int j=0;j<2;j++) {ans.push_back(v1[i]); ans.push_back(v1[i-1]); }
		}
		for(int i=0;i<ans.size();i++) cout << ans[i] << ' ';
		cout << "\n";
	}
	return 0;
}