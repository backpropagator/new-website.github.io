#include <bits/stdc++.h>
using namespace std;
int max_node;

int search(int node, int tc){
	int left = 2*node, right = left+1;
	if(left<max_node && right<max_node){
		if(tc%2 == 0){
			search(right,tc/2);
		}
		else if(tc%2 == 1){
			search(left,tc/2 + 1);
		}
	}else{
		return node;
	}
}


int main(){
	int n;
	cin>>n;
	int d, k;
	while(n--){
		cin>>d>>k;
		max_node = pow(2,d);
		cout<<search(1,k)<<"\n";
	}
}