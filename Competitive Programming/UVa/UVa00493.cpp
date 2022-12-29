#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back
typedef long long ll;
using namespace std;


//visited[(double)y/(double)x]
int change(int dir){
	if(dir == 0) return 1;
	else if(dir == 1) return 2;
	else if(dir == 2) return 3;
	else return 0;
}
 
int main(){
    ios_base::sync_with_stdio(false);

	ll n;
	while(cin>>n){
		vector<ll> num, den;
		map<double,bool> visited;
		ll x=0, y=1;
		int dir = 3;
		//visited[(double)y/(double)x] = true;
		while(num.size() < n+1){

			if((x == y) || (-1*x == y && x > 0) || (-1*x + 1 == y && x < 0)){
				dir = change(dir);
			}

			if(dir == 0){
				y--;
			}
			else if(dir == 1){
				x--;
			}
			else if(dir == 2){
				y++;
			}
			else if(dir == 3){
				x++;
			}

			if(x != 0 && !visited[(double)y/(double)x]){
				ll tx = x, ty = y;
				if(ty<0 && tx<0){
					ty *= -1;
					tx *= -1;
				}
				else if(tx<0 && ty>0){
					ty *= -1;
					tx *= -1;
				}
				num.pb(ty), den.pb(tx);
				visited[(double)ty/(double)tx] = true;
			}
		}
		cout<<num[n]<<" / "<<den[n]<<"\n";
	}
}

