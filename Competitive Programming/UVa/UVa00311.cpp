#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	ll a, b, c, d, e, f;

	while(cin>>a>>b>>c>>d>>e>>f && a+b+c+d+e+f){
		ll parcel = 0;
		parcel += f;

		parcel += e;
		a -= 11*e;

		parcel += d;
		b -= 5*d;

		parcel += c/4;

		if(c%4 != 0){
			int g = c%4;
			if(g == 1){
				b -= 5;
				a -= 7;
			}
			else if(g == 2){
				b -= 3;
				a -= 6;
			}
			else if(g == 3){
				b -= 1;
				a -= 5;
			}
			parcel++;
		}

		if(b > 0){
			parcel += b/9;
			if(b%9 > 0){
				parcel++;
				b -= 36 - ((b%9) * 4);
			}
		}else if(b < 0){
			a -= (-b)*4;
		}
		if(a > 0){
			parcel += a/36;
			if(a%36 > 0){
				parcel++;
			}
		}
		cout<<parcel<<"\n";
	}
}