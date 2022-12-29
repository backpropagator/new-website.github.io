#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
	int n;
	cin>>n;
	int frnd[n], g[n];
	for (int i = 0; i < n; ++i)
		{
			cin>>frnd[i];
			frnd[i]--;
			g[frnd[i]] = i;
		}	
	for (int i = 0; i < n; ++i)
	{
		cout<<g[i]+1<<" ";
	}
}