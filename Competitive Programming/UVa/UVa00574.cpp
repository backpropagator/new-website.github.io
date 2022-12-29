#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t, n, cnt;
vector<ll> num;
map<vector<ll>,bool> used;

void backtrack(int k, int pos, ll sum, vector<ll> sol){
	if(sum == t){
		if(!used[sol]){
			cnt++;
			for (int i = 0; i < k; ++i)
			{
				cout<<sol[i];
				if(i != k-1){
					cout<<"+";
				}
			}
			used[sol] = true;
			cout<<"\n";
			return;
		}
	}
	if(sum > t || pos == n) return;
	else{
		for(int i=pos; i<n; i++){
			//sum += num[i];
			sol.push_back(num[i]);
			backtrack(k+1,i+1,sum+num[i],sol);
			sol.pop_back();
		}
	}
}

int main(){
	ll a;
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	while(cin>>t>>n && t+n){
		cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a;
			num.push_back(a);
		}
		used.clear();
		cout<<"Sums of "<<t<<":\n";
		sort(num.begin(),num.end(),greater<int>());
		vector<ll> solution;
		//sol.push_back(num[0]);
		//ll sum = 0;
		backtrack(0,0,0,solution);
		if(cnt == 0){
			cout<<"NONE\n";
		}
		//sol.clear();
	}
}