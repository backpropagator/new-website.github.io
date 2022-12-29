#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

  	ll n;
  	cin>>n;
  	set<ll> st;
  	set<ll> :: iterator it;
  	for(ll i=1;i<=sqrt(n);i++)
  	{
  		if(n%i==0)
  		{
  			ll g=n/i;
  			st.insert((g*(1+n+1-i))/2);
  			st.insert((i*(1+n+1-g))/2);
  		}
  	}
  	for(it=st.begin();it!=st.end();it++)cout<<*it<<" ";
	return 0;
}