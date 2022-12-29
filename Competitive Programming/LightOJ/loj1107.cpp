#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, x1, y1, x2, y2;
	cin>>t;
	int x, y;
	int c, p=1;
	while(t--){
		cin>>x1>>y1>>x2>>y2;
		cin>>c;
		cout<<"Case "<<p<<":\n";
		while(c--){
			cin>>x>>y;
			//cout<<"Case "<<p<<": ";
			if(x<x1 || x>x2 || y<y1 || y>y2){
				cout<<"No\n";
			}else{
				cout<<"Yes\n";
			}
		}
		p++;
	}
} 