#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll n, a, b;
	cin>>n>>a>>b;
	ll p = min(a,b), q = a+b-n;
	if(q <= 0){
		cout<<p<<" "<<0<<"\n";
	}else{
		cout<<p<<" "<<q<<"\n";
	}
}

