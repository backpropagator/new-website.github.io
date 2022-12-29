#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll w, h, u1, u2, d1, d2;
	cin>>w>>h>>u1>>d1>>u2>>d2;
	ll cur = h;
	while(cur >= 0){

		w += cur;
		if(cur == d1) w -= u1;
		else if(cur == d2) w -= u2;
		if(w <= 0) w =0;
		cur--;
		
	}
	if(w <= 0) w = 0;

	cout<<w<<"\n";
}