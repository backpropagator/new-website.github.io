#include <bits/stdc++.h>
typedef long long ll; 
using namespace std;
ll n;
vector<ll> a;

int main(){
	cin>>n;
	ll b;
	for (int i = 0; i < n; ++i)
	{
		cin>>b;
		a.push_back(b);
	}
	//memo[0] = 1;
	ll max = 1, len = 1;
	for (int i = 1; i < n; ++i)
	{
		if(a[i] >= a[i-1]){
			len++;
		}else{
			if(max < len){
				max = len;
			}
			len = 1;
		}
	}
	if(max < len)
		max = len;
	
	cout<<max<<"\n";
}