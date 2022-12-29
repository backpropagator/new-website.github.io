#include <bits/stdc++.h>
using namespace std;

int main() {
	
	long long int n,cost[100000],total[100000],res1,res2; 
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>cost[i];
	
	total[0]=cost[0];
	total[1]=cost[0]+cost[1];
	total[2]=cost[0]+cost[2];
	for(int i=3;i<n;i++){
		total[i]=cost[i]+min(total[i-1],total[i-2]);
	}
	res1=min(total[n-1],total[n-2]); 

	total[0]=cost[0];
	total[1]=cost[1];
	for(int i=2;i<n;i++){
		total[i]=cost[i]+min(total[i-1],total[i-2]);
	}
	res2=total[n-1];
	cout<<min(res1,res2)<<endl;
	return 0;
}