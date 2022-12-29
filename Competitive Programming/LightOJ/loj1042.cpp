#include<bits/stdc++.h>
using namespace std;

unsigned int binary(int x){
	unsigned int right;
	unsigned int nexth;
	unsigned int patt;
	unsigned int next;

	if(x){
		right = x & -(signed)x;
		nexth = x + right;
		patt = x ^ nexth;
		patt = patt/right;
		patt >>= 2;
		next = nexth | patt;
	}
	return next;
}

int main(){
	int t;
	cin>>t;
	int p=1;
	int n;
	while(t--){
		cin>>n;
		cout<<"Case "<<p<<": ";
		cout<<binary(n)<<"\n";
		p++;
	}
}