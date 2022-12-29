#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc, n;
	cin>>tc;
	string grid;
	for (int j = 1; j <= tc; ++j)
	{
		cin>>n;
		cin>>grid;
		bool g[n] = {false};
		int cnt = 0;
		for (int i = 0; i < n;)
		{
			if(grid[i] == '#'){
				i++;
			}else{
				cnt++;
				i += 3;
			}
		}
		printf("Case %d: %d\n",j,cnt);
	}
}