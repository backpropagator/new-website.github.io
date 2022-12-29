#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	n++;
	if(n == 1){
		cout<<0<<"\n";
	}else{
		if(n%2 == 0){
			cout<<n/2<<"\n";
		}else{
			cout<<n<<"\n";
		}
	}
}