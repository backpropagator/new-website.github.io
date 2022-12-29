#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int t;
	ll n, v1, v2;
	cin>>t;
	while(t--){
		cin>>n>>v1>>v2;
		bool watching = true;
		ll x = 0, y = 0;
		char c;
		for (int i = 0; i < n; ++i)
		{
			cin>>c;
			if(c == '*'){
				watching = !watching;
				continue;
			}else{
			if(watching){
				if(c == 'N'){
					y += v1;
				}
				else if(c == 'S'){
					y -= v1;
				}
				else if(c == 'E'){
					x += v1;
				}
				else if(c == 'W'){
					x -= v1;
				}
			}else{
				if(c == 'N'){
					y += v2;
				}
				else if(c == 'S'){
					y -= v2;
				}
				else if(c == 'E'){
					x += v2;
				}
				else if(c == 'W'){
					x -= v2;
				}
			}}
			//cout<<x<<" "<<y<<"\n";
		}
		if(max(abs(x),abs(y))%2 == 1)
			cout<<"W\n";
		else
			cout<<"B\n";
	}
} 