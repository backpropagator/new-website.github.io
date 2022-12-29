#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int s[n], j[n];
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>s[i]>>j[i];
			if(j[i]-s[i] > 5)
				cnt++;
		}
		cout<<cnt<<"\n";
	}
}