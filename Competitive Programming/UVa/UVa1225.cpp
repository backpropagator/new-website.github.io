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
		ll a[10] = {0};
		for (int i = 1; i <= n; ++i)
		{
			int j = i;
			while(j != 0){
				int k = j%10;
				a[k]++;
				j /= 10;
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			cout<<a[i];
			if(i != 9){
				cout<<" ";
			}
		}
		cout<<"\n";
	}
}

