#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<double,int> &p1, pair<double,int> &p2){
	return p2.first < p1.first;
}

int main(){
	int tc,n,N,s;
	cin>>tc;

	while(tc--){
		cin>>N;
		vector<pair<double,int>> rel;
		for (int i = 1; i <= N; ++i)
		{
			cin>>n>>s;
			pair<double,int> tmp;
			tmp.first = (double)s/(double)n;
			tmp.second = i;
			rel.push_back(tmp);
		}

		sort(rel.begin(),rel.end(),cmp);
		
		for (int i = 0; i < N; ++i)
		{
			cout<<rel[i].second;
			if(i != N-1)
				cout<<" ";
		}

		cout<<"\n";
		if(tc)
			cout<<"\n";
	}
}