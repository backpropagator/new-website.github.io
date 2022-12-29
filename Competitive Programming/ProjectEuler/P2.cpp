#include <bits/stdc++.h>
#define Max 4000000
typedef long long ll;
using namespace std;

int main(){
	vector<ll> fib;
	ll x = 1, y = 2;
	ll tmp, pnt = 2, cnt = 2;
	while(1){
		tmp = x + y;
		if(tmp > Max)
			break;
		if(tmp%2 == 0)
			cnt += tmp;
		//y = x;
		y = max(x,y);
		x = tmp;
		pnt++;
	}
	cout<<cnt<<"\n";

}