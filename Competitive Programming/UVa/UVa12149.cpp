#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll sqr[103];
    sqr[0] = 1, sqr[1] = 1;
    for (int i = 2; i < 103; ++i)
    {
    	sqr[i] = sqr[i-1] + (i*i);
    }

	ll n;
	while(cin>>n && n){
		cout<<sqr[n]<<"\n";
	}
	
}

