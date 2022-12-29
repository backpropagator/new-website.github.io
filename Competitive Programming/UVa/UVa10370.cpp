#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    
	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		ll v[n], sum=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			sum += v[i];
		}
		double avg = sum/n;
		//cout<<avg<<"\n";
		ll cnt=0;
		for (int i = 0; i < n; ++i)
		{
			if((double)v[i] > avg) cnt++;
		}
		//cout<<cnt<<"\n";
		cout << fixed;
		double pct = ((double)cnt/(double)n)*100;
		cout<<setprecision(3)<<pct<<"%\n";
		//cout<<"%\n";

	}
}

