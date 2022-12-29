#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  ll n, k;
  cin>>n>>k;
  ll v[n];
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];
  }
  map<ll,ll> frq;
  for (int i = 0; i < n; ++i)
  {
    ll tmp = v[i]%k;
    frq[tmp]++;
  }
  ll cnt = 0;
  bool iseven = ((k/2)*2 == k);
  for (int i = 1; i <= k/2; ++i)
  {
    if(!iseven || (iseven && i != k/2))
      cnt += min(frq[i],frq[k-i]);
  }
  cnt += (frq[0]/2);
  if(iseven)
    cnt += (frq[k/2]/2);
  //cout<<iseven;
  cout<<cnt*2<<"\n";

}