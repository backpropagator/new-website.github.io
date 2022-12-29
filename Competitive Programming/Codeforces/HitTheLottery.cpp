#include <bits/stdc++.h>
using namespace std;

int cash[] = {1,5,10,20,100};

int main(){
	int n;
	cin>>n;
	int cnt = 0, ptr = 4;
	while(n != 0){
		if(cash[ptr] > n)
			ptr--;
		else{
			n = n - cash[ptr];
			cnt++;
		}
	}
	cout<<cnt<<"\n";
}