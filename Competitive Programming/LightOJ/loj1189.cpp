#include<bits/stdc++.h>
using namespace std;

long long factorial(int n){
	long long result = 1;
	for(int i=1; i<=n; i++){
		result *= i;
	}
	return result;
}

long long fact[21];

int main(){
	fact[0] = 1;
	for(int i=1; i<21; i++){
		fact[i] = factorial(i);
	}

	int t;
	cin>>t;
	long long n;
	int p = 1;
	while(t--){
		cin>>n;
		
		vector<int> ans;
		for(int i=19; i>=0&&n>0; i--){
			if(fact[i] <= n){
				n = n - fact[i];
				ans.push_back(i);
			}
		}
		cout<<"Case "<<p<<": ";
		if(n != 0){
			cout<<"impossible\n";
		}else{
			//sort(ans.begin(),ans.end());
			for (int i = ans.size()-1; i >= 0; i--)
			{
				cout<<ans[i]<<"!";
				if(i != 0){
					cout<<"+";
				}
			}
			cout<<"\n";
		}
		p++;
	}

}