#include <bits/stdc++.h>
#define MAX 1000000001
typedef long long ll;
using namespace std;
vector<ll> arr(MAX);

void init(){
	ll i, j;
	//memset(arr, 0, sizeof arr);
	for(i=2; i<MAX; i++){
		for(j=1; j <= (MAX/pow(i,3)); j++){
			ll tmp = (int)pow(i,3)*j;
			arr[tmp]++;
		}
	}
}

int main(){
	ll t, n;
	cin>>t;
	init();
	while(t--){
		cin>>n;
		ll cnt = 0;
		for (int i = 0; i <= n; ++i)
		{
			if(arr[i] != 0){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
}