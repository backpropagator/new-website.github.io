#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	
	ll a, b, c, d, l;
	
	while(cin>>a>>b>>c>>d>>l && a+b+c+d+l){
		ll val, cnt=0;
		for (int i = 0; i <= l; ++i)
		{
			val = a*(i*i) + b*(i) + c;
			if(val%d == 0) cnt++;
		}
		cout<<cnt<<"\n";
	}
}

