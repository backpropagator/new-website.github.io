#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll s;
	cin>>s;
	if(s <= 90){
		cout<<0<<" No punishment\n";
	}
	else if(s >= 91 && s <= 110){
		cout<<(s-90)*300<<" Warning\n";
	}
	else if(s > 110){
		cout<<(s-90)*500<<" License removed\n";
	}
	return 0;
}