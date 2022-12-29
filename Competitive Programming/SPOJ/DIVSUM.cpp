#include <bits/stdc++.h>
using namespace std;

int DIVSUM(long long n){
	long long sum=0;
	int other;
	if(n == 1){
		return 0;
	}
	for(int i=2; i*i<=n; i++){
		if(n%i == 0){
			sum += i;
			other = n/i;
			if(i != other){
				sum += other;
			}
		}
	}
	return sum+1;
}

int main(){
	int t;
	cin>>t;
	long long n;
	while(t--){
		cin>>n;
		cout<<DIVSUM(n)<<"\n";
	}
}