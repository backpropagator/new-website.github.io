#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n, x, y;
	cin>>n>>x>>y;
	ll w = max(x,y)-1, b = n-min(x,y);
	if(w <= b)
		cout<<"White\n";
	else
		cout<<"Black\n";
}