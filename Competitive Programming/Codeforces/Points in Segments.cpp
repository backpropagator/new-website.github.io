#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int n, m, a, b;
	cin>>n>>m;
	int seg[m+1];
	memset(seg,0,sizeof seg);
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		for (int i = a; i <= b; ++i)
		{
			seg[i]++;
		}
	}
	vector<int> pt;
	int cnt = 0;
	for (int i = 1; i <= m; ++i)
	{
		if(seg[i] == 0){
			cnt++;
			pt.push_back(i);
		}
	}
	cout<<cnt<<"\n";
	for (int i = 0; i < pt.size(); ++i)
	{
		cout<<pt[i];
		if(i != pt.size()-1){
			cout<<" ";
		}
	}
	cout<<"\n";
}