#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isPal(ll x){
	ll y=0, z=x;
	while(z > 0){
		y = (y*10) + (z%10);
		z /= 10;
	}
	return y == x;
}


int main(){
	ll n, m=0, f, s;
	for(int i=100; i<= 999; i++){
		for(int j=100; j<= 999; j++){
			n = i*j;
			if(isPal(n) && n > m)
				m = n, f=i, s=j;
		}
	}
	cout<<m<<" "<<f<<" "<<s;
}