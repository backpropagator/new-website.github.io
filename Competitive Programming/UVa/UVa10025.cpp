#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		ll i=1;
		while(1){
			if(i*(i+1)/2 >= abs(n) && ((i*(i+1)/2)-abs(n))%2 == 0){
				break;
			}else{
				i++;
			}
		}
		cout<<i;
		if(t != 0){
			cout<<"\n\n";
		}else{
			cout<<"\n";
		}
	}
}

