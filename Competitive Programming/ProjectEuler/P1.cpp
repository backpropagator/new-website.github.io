#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll cnt = 0;
	for (int i = 0; i < 1000; ++i)
	{
		if(i%3 == 0 || i%5 == 0){
			cnt += i;
		}
	}
	cout<<cnt;
}