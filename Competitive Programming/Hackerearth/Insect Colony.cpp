#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc, n, tmp;
	cin>>tc;
	while(tc--){
		cin>>n;
		long long sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>tmp;
			sum = sum^tmp;
		}
		if(sum%2 == 0){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
}