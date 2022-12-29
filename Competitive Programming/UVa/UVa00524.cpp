#include <bits/stdc++.h>
using namespace std;
int n;
bool used[18];

bool isPrime(int n){
	if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 23 || n == 29 || n == 31)
		return true;
	else 
		return false;
}

void backtrack(int pos, vector<int>sol){
	if(pos == n-1 && isPrime(sol[n-1] + sol[0])){
		for (int i = 0; i < n; ++i)
		{
			cout<<sol[i];
			if(i != n-1){
				cout<<" ";
			}
		}
		cout<<"\n";
		return;
	}else{
		for (int i = 2; i <= n; ++i)
		{
			if(!used[i] && isPrime(sol[pos]+i)){
				used[i] = true;
				sol.push_back(i);
				backtrack(pos+1,sol);
				used[i] = false;
				sol.pop_back();
			}
		}
	}
}

int main(){
	int tc = 1;
	while(cin>>n){
		vector<int> solution;
		solution.push_back(1);
		used[1] = true;
		if(tc > 1){
			cout<<"\n";
		}
		printf("Case %d:\n", tc);
		backtrack(0,solution);
		tc++;
	}
}