#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> pairs;

int solve(int n){
	int i, j;
	int cnt = 0;
	pairs.clear();
	//vector<pair<int,int>> pairs;
	for (int i = n+1; i <= 2*n; ++i)
	{
		if(((i*n)%(i-n)) == 0){
			cnt++;
			pairs.push_back(make_pair((i*n)/(i-n),i));
		}
	}
	cout<<cnt<<"\n";
	for (int i = 0; i < pairs.size(); ++i)
	{
		printf("1/%d = 1/%d + 1/%d\n", n, pairs[i].first, pairs[i].second);
	}
	
}

int main(){
	int k;
	while(cin>>k){
		solve(k);
	}
}