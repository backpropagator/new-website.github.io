#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int top[n][m];
	char c;
	for (int i = 0; i < n; ++i)
	{
		for(int j=0; j<m; j++){
			cin>>c;
			c == '1' ? top[i][j] = 1 : top[i][j] = 0;
		}
	}
	map<int,int> maxtop;
	for (int i = 0; i < n; ++i)
	{
		//int cnt = 0;
		for(int j=0; j<n; j++)
		{
			int cnt = 0;
			for(int k=0; k<m; k++)
			{
				if(i == j)
					continue;
				if(top[i][k] || top[j][k])
					cnt++;
			}
			maxtop[cnt]++;
		}
	}
	map<int,int>::iterator it = maxtop.begin();
	int ans1 = 0, ans2 = 0;
	for(it = maxtop.begin(); it != maxtop.end(); it++){
		ans1 = max(ans1,it->first);
	}
	cout<<ans1<<"\n"<<maxtop[ans1]/2<<"\n";
}