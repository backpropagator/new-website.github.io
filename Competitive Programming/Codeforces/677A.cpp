#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll n, h;
	cin>>n>>h;
	ll v[n];
	ll cnt=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		if(v[i] > h) cnt += 2;
		else cnt++;
	}
	cout<<cnt<<"\n";
}

