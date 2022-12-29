#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int n, m;
	cin>>n;
	while(n--){
		cin>>m;
		ll w[m];
		for (int i = 0; i < m; i++)
		{
			cin>>w[i];
		}
		ll lis[m], lds[m], ma = 0;
		lis[0] = 1;
		lds[0] = 1;
		//cout<<"\n";
		for (int i = 1; i < m; i++)
		{
			ll tmp = 1;
			for(int j = 0; j<i; j++){
				if(w[j] < w[i]){
					tmp = max(tmp,1 + lis[j]);
				}
			}
			lis[i] = tmp;
			//cout<<lis[i]<<"\n";
		}
		//cout<<"\n";
		for (int i = 1; i < m; i++)
		{
			ll tmp = 1;
			for(int j = 0; j<i; j++){
				if(w[j] > w[i]){
					tmp = max(tmp,1 + lds[j]);
				}
			}
			lds[i] = tmp;
			//cout<<lds[i]<<"\n";
		}
		//cout<<"\n";

		for (int i = 0; i < m; ++i)
		{
			ma = max(ma,lis[i]+lds[i]-1);
		}
		cout<<m<<"\n";
	}
}