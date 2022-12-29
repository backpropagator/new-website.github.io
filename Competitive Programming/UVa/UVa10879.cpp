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
	ll tst=1;
	while(t--){
		cin>>n;
		ll cnt=0;
		ll a, b;
		for (int i = 2; i < sqrt(n); ++i)
		{
			if(n%i == 0){
				if(cnt == 0){
					cnt++;
					a = i;
				}
				else if(cnt == 1){
					cnt++;
					b = i;
					break;
				}
			}
		}
		cout<<"Case #"<<tst<<": "<<n<<" = ";
		cout<<a<<" * "<<n/a<<" = "<<b<<" * "<<n/b<<"\n";
		tst++;
	}
}

