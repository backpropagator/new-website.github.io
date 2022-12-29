#include <bits/stdc++.h>
using namespace std;
int n, m, sol, sum, timee[25];
//int time[25];
vector<int> tmp, ans;

void backtrack(int id, int sum){
	if(sum > sol){
		sol = sum;
		ans = tmp;
	}
	for (int i = id; i < m; ++i)
	{
		if(sum + timee[i] <= n){
			tmp.push_back(timee[i]);
			backtrack(i+1,sum+timee[i]);
			tmp.pop_back();
		}
	}
	return;
}

int main(){
	int a, b;
	//vector<int> pairs;
	while(cin>>n>>m){
		sum = 0;
		sol = 0;
		//count = 0;
		for (int i = 0; i < m; ++i)
		{
			cin>>timee[i];
			
		}
		tmp.clear();
		ans.clear();
		backtrack(0,0);
		for(vector<int>::iterator itr = ans.begin(); itr != ans.end(); itr++){
			cout<<*itr<<" ";
		}	
		cout<<"sum:"<<sol<<"\n";
	}
}