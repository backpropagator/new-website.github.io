#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n, m;
	cin>>n>>m;
	char tbl[n+1][m+1];
	int r1, c1, r2, c2;
	ll cnt  = 0;
	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			cin>>tbl[i][j];
			if(tbl[i][j] == 'B'){
				cnt++;
				r2 = i;
				c2 = j;
			}
		}
	}
	if(cnt == 1){
		cout<<r2<<" "<<c2<<"\n";
	}
	else if(cnt > 1){
		bool breakable = false;
		for(int i=1; i<n+1; i++){
			for(int j=1; j<m+1; j++){
				if(tbl[i][j] == 'B'){
					breakable = true;
					r1 = i;
					c1 = j;
					break;
				}
			}
			if(breakable)
				break;
		}
		cout<<(r1+r2)/2<<" "<<(c1+c2)/2<<"\n";
	}


}