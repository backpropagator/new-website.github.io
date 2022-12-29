#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n;
	cin>>n;
	ll arr[n][n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>arr[i][j];
			if(i > 0){
				arr[i][j] += arr[i-1][j];
			}
			if(j > 0){
				arr[i][j] += arr[i][j-1];
			}
			if(i > 0 && j > 0){
				arr[i][j] -= arr[i-1][j-1];
			}
		}
	}

	ll sum = -1*127*100*100;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=i; k<n; k++){
				for(int l=j; l<n; l++){
					ll tmp = arr[k][l];
					if(i > 0) tmp -= arr[i-1][l];
					if(j > 0) tmp -= arr[k][j-1];
					if(i > 0 && j > 0) tmp += arr[i-1][j-1];
					sum = max(sum,tmp);
				}
			}
		}
	}
	cout<<sum<<"\n";

}