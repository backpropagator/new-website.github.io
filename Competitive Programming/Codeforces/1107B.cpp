#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll n, k, x;
	cin>>n;
	while(n--){
		cin>>k>>x;
		cout<<9*(k-1) + x<<"\n";
	}
}

