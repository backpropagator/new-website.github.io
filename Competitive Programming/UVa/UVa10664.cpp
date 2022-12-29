#include <bits/stdc++.h>
#define pb(a) push_back(a)
typedef long long ll;
using namespace std;

vector<int> v;
int memo[105][25];

int dp(int remaining, int idx){
	if(remaining == 0)
		return 0;

	if(memo[remaining][idx] != -1){
		return memo[remaining][idx];
	}
	int sum = 0, mx = 0;
	for (int i = idx; i < v.size(); ++i)
	{
		if(v[i] <= remaining){
			sum = (v[i] + dp(remaining-v[i],i+1));
			if(mx < sum) mx = sum;
		}
	}
	return memo[remaining][idx] = mx;
}


int main(){
	int tc;
	cin>>tc;
	getchar();
	while(tc--){
		memset(memo,-1,sizeof(memo));
		string str;
		int value, sum = 0;
		getline(cin,str);
		stringstream ss;
		ss<<str;
		while(ss>>value){
			v.pb(value);
			sum += value;
		}
		if(sum%2 != 0){
			cout<<"NO"<<"\n";
		}
		else{
			if(dp(sum/2,0) == sum/2)
				cout<<"YES"<<"\n";
			else
				cout<<"NO"<<"\n";
		}
		v.clear();
	}
}