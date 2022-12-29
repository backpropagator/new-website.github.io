#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		int arr[n];
		int s=0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			s += arr[i];
		}
		bool sum[n+1][s+1];
		memset(sum, 0, sizeof(sum));
		for(int i=0; i<=n; i++){
			sum[i][0]=true;
		}
		//sum[0][0]=true;
		for(int i=1; i<=n; i++){
			//sum[i][0] = true;
			sum[i][arr[i-1]] = true;
			for(int j=1; j<=s; j++){

				if(sum[i-1][j] == true){
					sum[i][j] = true;
					sum[i][j + arr[i-1]] = true;
				}
			}
		}
		int act = 0;
		for(int j=0; j<=s; j++){
			if(sum[n][j]){
				act += j;
				//cout<<"";
			}
		}
		//cout<<"\n";
		cout<<act<<"\n";
	}
}