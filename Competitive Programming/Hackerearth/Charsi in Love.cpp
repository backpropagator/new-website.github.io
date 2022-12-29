#include <bits/stdc++.h>
#define N 100000005
using namespace std;
unsigned long long int desperate[N];

void init(int n){
	desperate[0] = 0;
	desperate[1] = 1;
	for (long long int i = 2; i <= n; ++i)
	{
		desperate[i] = i + desperate[i-1];
	}
} 

int main(){
	//init();
	long long int n;
	cin>>n;
	long long int ptr1=n-1, ptr2=1, sum;
	init(n);
	string ans;
	bool solved = false;
	while(ptr1>1 && ptr2<n && ptr1 > ptr2){
		sum = desperate[ptr1] + desperate[ptr2];
		if(sum > n){
			ptr1--;
		}
		else if(sum < n){
			ptr2++;
		}
		else if(sum == n){
			solved = true;
			break;
		}
	}
	if(solved)
		cout<<"YES"<<"\n";
	else
		cout<<"NO"<<"\n";
}