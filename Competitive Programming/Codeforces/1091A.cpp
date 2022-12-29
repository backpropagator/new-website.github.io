#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll y, b, r;
	cin>>y>>b>>r;
	ll l = min(y, min(b,r));
	if(l == r){
		cout<<(3*r)-3<<"\n";
	}
	else if(l == b){
		cout<<3*b<<"\n";
	}else{
		if(r-y >= 2 && b-y >= 1){
			cout<<(3*y)+3<<"\n";
		}
		else if(r-y >= 1){
			cout<<(3*r)-3<<"\n";
		}

	}
}