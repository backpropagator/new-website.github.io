#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll a;
	int t = 1;
	while(cin>>a && a != -1){
		vector<ll> missile;
		bool isZero = false;
		if(a == 0){
			/*printf("Test #%d:\n",t++);
			printf("  maximum possible interceptions: 0\n\n");
			t++;*/
			isZero = true;
		}
		missile.push_back(a);
		while(cin>>a && a != -1)
			missile.push_back(a);
		ll lds[missile.size()];
		lds[0] = 1;
		ll ov = 0;
		for(int i=1; i<missile.size(); i++){
			ll ans = 1;
			for(int j=0; j<i; j++){
				if(missile[i] <= missile[j]){
					ans = max(ans,(1+lds[j]));
				}
			}
			lds[i] = ans;
			ov = max(ov,lds[i]);
		}
		if(!isZero){
			cout << "Test #" << t++ << ":" << endl;
        	cout << "  maximum possible interceptions : " << ov <<"\n"<< endl;
		}else{
			cout << "Test #" << t++ << ":" << endl;
        	cout << "  maximum possible interceptions : " << 0 <<"\n"<< endl;
		}
	}
	return 0;
}