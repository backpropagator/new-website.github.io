#include <bits/stdc++.h>
#define inf -10000000
typedef long long ll;
using namespace std;

int main(){
	int m, n;
	while(cin>>m>>n && m+n){
		ll arr[m][n];
		ll a;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cin>>a;
				arr[i][j] = (a == 1 ? inf : 1);
				if(i > 0) arr[i][j] += arr[i-1][j];
				if(j > 0) arr[i][j] += arr[i][j-1];
				if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
			}
		}
		ll sum = inf - 1;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				for(int k=i; k<m; k++){
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
}
