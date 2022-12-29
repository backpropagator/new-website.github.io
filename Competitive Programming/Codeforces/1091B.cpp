#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n;
	cin>>n;
	ll x[n], y[n], a[n], b[n];
	ll sx=0, sy=0, sa=0, sb=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>x[i]>>y[i];
		sx += x[i];
		sy += y[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i]>>b[i];
		sa += a[i];
		sb += b[i];
	}
	ll tx = (sx+sa)/n, ty = (sy+sb)/n;
	cout<<tx<<" "<<ty<<"\n";

}